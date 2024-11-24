#pragma once

#include "hezel/input.h"

namespace hezel
{
    class LinuxInput : public HezelInput
    {
    public:
        virtual bool IsKeyImpressedImpl(int keycode) override;
        virtual bool IsMouseButtonPressedImpl(int button) override;
        virtual std::pair<float, float> GetMousePositionImpl() override;
        virtual float GetMouseXImpl() override;
        virtual float GetMouseYImpl() override;
    };
}