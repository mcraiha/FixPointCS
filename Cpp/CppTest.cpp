//
// FixPointCS
//
// Copyright(c) 2018 Jere Sanisalo, Petri Kero
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
#include <iostream>

#include "Fixed64.h"

int main()
{
	double v = 0.0001f;

	while (v < 150.f)
	{
		Fixed64::FP_LONG fv = Fixed64::FromDouble(v);
		Fixed64::FP_LONG fv_div = Fixed64::Div(fv, Fixed64::FromDouble(-2.34));
		Fixed64::FP_LONG fv_sqrt = Fixed64::Sqrt(fv);
		Fixed64::FP_LONG fv_sin = Fixed64::SinPoly5(fv);

		std::cout << v
			<< ": div_by_-2.34: " << Fixed64::ToDouble(fv_div)
			<< ", sqrt: " << Fixed64::ToDouble(fv_sqrt)
			<< ", sin: " << Fixed64::ToDouble(fv_sin)
			<< std::endl;

		// Next number
		v *= 1.5f;
	}

    return 0;
}
