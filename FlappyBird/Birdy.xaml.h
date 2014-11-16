//
// Birdy.xaml.h
// Declaration of the Birdy class
//

#pragma once

#include "Birdy.g.h"

namespace FlappyBird
{
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class Birdy sealed
	{
	public:
		Birdy();

	private:
		void Life();
		void OnTick(Platform::Object ^sender, Platform::Object ^args);
	};
}
