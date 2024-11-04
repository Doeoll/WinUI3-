#pragma once

#include "MainWindow.g.h"
#include <winrt/Microsoft.Graphics.Canvas.UI.Xaml.h> // for canvas
#include <winrt/Microsoft.UI.Input.h>  // for point_click
#include <winrt/Microsoft.UI.Xaml.Input.h> // for canvs point_click

namespace winrt::App8::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);
        bool flag;
        float px, py;
        std::vector<float> vx;
        std::vector<float> vy;

        void CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args);
        void CanvasControl_PointerMoved(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e);
        void ColorPicker_ColorChanged(winrt::Microsoft::UI::Xaml::Controls::ColorPicker const& sender, winrt::Microsoft::UI::Xaml::Controls::ColorChangedEventArgs const& args);
        void CanvasControl_PointerPressed(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e);
        void CanvasControl_PointerReleased(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e);
    };
}

namespace winrt::App8::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
