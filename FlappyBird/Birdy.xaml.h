//
// Birdy.xaml.h
// Declaration of the Birdy class
//

#pragma once

#include "Birdy.g.h"

using Windows::UI::Xaml::Controls::Canvas;
using Windows::UI::Xaml::DispatcherTimer;

namespace FlappyBird
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Birdy sealed
	{
	public:
		Birdy();

	internal:
		property double Left
		{
			double get()
			{
				return _left;
			}
			void set(double value)
			{
				//manage intersections
				Canvas::SetLeft(this, value);
				_left = value;
			}
		}

		property double Top
		{
			double get()
			{
				return _right;
			}
			void set(double value)
			{
				//manage intersections
				Canvas::SetTop(this, value);
				_right = value;
			}
		}

		void Flap();

	private:
		double _left, _right;
		DispatcherTimer ^FlapTimer;

		void Life();
		void OnTick(Platform::Object ^sender, Platform::Object ^args);
		void OnFlap(Platform::Object ^sender, Platform::Object ^args);
	};
}
