#include <math.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <random>
#include <numeric>
#include <exception>
#include <memory>
#include <chrono>
#include <functional>

#include <omp.h>

#include "tbb/parallel_reduce.h"
#include "tbb/blocked_range.h"

#include "curves.h"

static const int SIZE = 10;

int main() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> disd(1.0, 2.0);
	std::uniform_int_distribution<> disi(1, 3);
	
	std::vector<std::shared_ptr<Curve>> v(SIZE);
	for (int i = 0; i < v.size();) {
		int c = disi(gen);
		try {
			switch (c) {
				case 1:
					v[i++] = std::make_shared<Circle>(disd(gen));
					break;
				case 2:
					v[i++] = std::make_shared<Ellipse>(disd(gen), disd(gen));
					break;
				case 3:
					v[i++] = std::make_shared<Helix>(disd(gen), disd(gen));
					break;
				default:
					//
					break;
			}
		}
		catch (std::invalid_argument & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	
	std::for_each(v.begin(), v.end(), [](std::shared_ptr<Curve> c) {
		const static double t = M_PI / 4;
		static int i = 0;
		std::cout << i++ << ": value" << c->point(t) << ", derivative" << c->first_derivative(t) << std::endl;
	});
	
	std::vector<std::shared_ptr<Circle>> w;
	for (int i = 0; i < v.size(); ++i) {
		if (std::shared_ptr<Circle> c = std::dynamic_pointer_cast<Circle>(v[i])) w.push_back(c);
	}
	
	std::sort(w.begin(), w.end(), [](std::shared_ptr<Circle> c1, std::shared_ptr<Circle> c2) {
		return c1->get_radius() < c2->get_radius();
	});
	std::for_each(w.begin(), w.end(), [](std::shared_ptr<Circle> c) {
		std::cout << c->get_radius() << " ";
	});
	std::cout << std::endl;
	

	auto start = std::chrono::steady_clock::now();
	double sum = std::accumulate(w.begin(), w.end(), 0.0, [](double res, std::shared_ptr<Circle> c) {
		return res + c->get_radius();
	});
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Total sum of radii is " << sum << ", time: " << diff.count() << std::endl;


	start = std::chrono::steady_clock::now();
	sum = 0.0;
	#pragma omp parallel for num_threads(4)
		for (auto p = w.begin(); p != w.end();++p) {
			#pragma omp atomic 
			{
				sum += (*p)->get_radius();
			}
		}
	end = std::chrono::steady_clock::now();
	diff = end - start;
	std::cout << "Total sum of radii is " << sum << ", time: " << diff.count() << " [OpenMP]" << std::endl;
	

	start = std::chrono::steady_clock::now();
	sum = tbb::parallel_reduce(tbb::blocked_range<int>(0, w.size()), 0.0, [&](tbb::blocked_range<int> range, double s) {
		for (int i = range.begin(); i != range.end(); ++i) s += w[i]->get_radius();
		return s;
	}, std::plus<double>());
	end = std::chrono::steady_clock::now();
	diff = end - start;
	std::cout << "Total sum of radii is " << sum << ", time: " << diff.count() << " [TBB]" << std::endl;

	
	return 0;
}