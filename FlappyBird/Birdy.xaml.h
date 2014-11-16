//
// Birdy.xaml.h
// Declaration of the Birdy class
//

#pragma once

#include "Birdy.g.h"

using Windows::UI::Xaml::DispatcherTimer;

namespace FlappyBird
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Birdy sealed
	{
	public:
		Birdy();

	internal:
		void Flap();

	private:
		DispatcherTimer ^FlapTimer;

		void Life();
		void OnTick(Platform::Object ^sender, Platform::Object ^args);
		void OnFlap(Platform::Object ^sender, Platform::Object ^args);
	};
}
