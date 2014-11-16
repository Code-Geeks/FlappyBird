//
// IncommingThing.xaml.h
// Declaration of the IncommingThing class
//

#pragma once

#include "IncommingThing.g.h"

namespace FlappyBird
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class IncommingThing sealed
	{
	internal:
		void Life();

	public:
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

		property double Speed
		{
			double get()
			{
				return _speed;
			}

			void set(double value)
			{
				_speed = value;
			}
		}

		IncommingThing();

	private:
		double _left, _right, _speed;
		void OnTick(Platform::Object ^sender, Platform::Object ^args);
	};
}
