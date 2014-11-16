//
// IncommingThing.xaml.cpp
// Implementation of the IncommingThing class
//

#include "pch.h"
#include "IncommingThing.xaml.h"

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

IncommingThing::IncommingThing()
{
	InitializeComponent();

	auto current = Window::Current;
	auto width = current->Bounds.Width;

	Left = width;
	Speed = 3;

	Life();
}

void IncommingThing::Life()
{
	auto timer = ref new DispatcherTimer();
	timer->Tick +=ref new Windows::Foundation::EventHandler<Platform::Object ^>(this, &FlappyBird::IncommingThing::OnTick);
	timer->Start();
}

void IncommingThing::OnTick(Object ^sender, Object ^args)
{
	auto currentWindow = Window::Current;
	auto bounds = currentWindow->Bounds;

	auto minLeft = -Width * 1.5;
	auto thingLeft = Canvas::GetLeft(this);

	if (thingLeft > minLeft)
		Left -= Speed;
}
