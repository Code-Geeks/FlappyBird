//
// Birdy.xaml.cpp
// Implementation of the Birdy class
//

#include "pch.h"
#include "Birdy.xaml.h"
#include <ppltasks.h>

using namespace FlappyBird;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The User Control item template is documented at http://go.microsoft.com/fwlink/?LinkId=234236

Birdy::Birdy()
{
	InitializeComponent();

	FlapTimer = ref new DispatcherTimer();
	FlapTimer->Tick += ref new Windows::Foundation::EventHandler<Platform::Object ^>(this, &FlappyBird::Birdy::OnFlap);

	Life();
}

void Birdy::Life()
{
	TimeSpan liferate = TimeSpan();

	auto timer = ref new DispatcherTimer();

	timer->Tick+=ref new EventHandler<Object ^>(this, &Birdy::OnTick);
	timer->Start();
}

void Birdy::Flap()
{
	if (FlapTimer->IsEnabled == false)
		FlapTimer->Start();
}

void Birdy::OnTick(Object ^sender, Object ^args)
{
	auto currentWindow = Window::Current;
	auto bounds = currentWindow->Bounds;

	auto maxTop = bounds.Height + Height;
	auto birdTop = Canvas::GetTop(this);

	if (birdTop < maxTop)
		Canvas::SetTop(this, Canvas::GetTop(this) + 3);
}

void Birdy::OnFlap(Object ^sender, Object ^args)
{
	static int i;

	if (i >= 0 && i < 10)
	{
		auto y = i == 0 ? 45.0 : i == 1 ? 20.0 : i == 2 ? 15.0 : i == 3 ? 10.0 : i == 4 ? 5.0 : 2.0;
		y = Height * y / 100.0;

		Canvas::SetTop(this, Canvas::GetTop(this) - y);
	}
	else
	{
		if (i < 30)
			Canvas::SetTop(this, Canvas::GetTop(this) + 1);
	}

	i++;
	if (i == 30)
	{
		FlapTimer->Stop();
		i = 0;
	}
}
