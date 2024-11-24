#pragma once
#include "core.h"

namespace hezel
{
    class HezelInput
    {
    public:
        inline static bool IsKeyImpressed(int keycode) {
            return s_input_->IsKeyImpressedImpl(keycode);
        }
        inline static bool IsMouseButtonPressed(int button) {
            return s_input_->IsMouseButtonPressedImpl(button);
        }
        inline static std::pair<float, float> GetMousePosition() {
            return s_input_->GetMousePositionImpl();
        }
        inline static float GetMouseX() {
            return s_input_->GetMouseXImpl();
        }
        inline static float GetMouseY() {
            return s_input_->GetMouseYImpl();
        }
    protected:
        virtual bool IsKeyImpressedImpl(int keycode) = 0;
        virtual bool IsMouseButtonPressedImpl(int button) = 0;
        virtual std::pair<float, float> GetMousePositionImpl() = 0;
        virtual float GetMouseXImpl() = 0;
        virtual float GetMouseYImpl() = 0;

    private:
        static HezelInput* s_input_;
    };
}