/// @file
/// @author David Pilger <dpilger26@gmail.com>
/// [GitHub Repository](https://github.com/dpilger26/NumCpp)
///
/// License
/// Copyright 2018-2023 David Pilger
///
/// Permission is hereby granted, free of charge, to any person obtaining a copy of this
/// software and associated documentation files(the "Software"), to deal in the Software
/// without restriction, including without limitation the rights to use, copy, modify,
/// merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
/// permit persons to whom the Software is furnished to do so, subject to the following
/// conditions :
///
/// The above copyright notice and this permission notice shall be included in all copies
/// or substantial portions of the Software.
///
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
/// INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
/// PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
/// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
/// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
/// DEALINGS IN THE SOFTWARE.
///
/// Description
/// Coordinate Transforms
///
#pragma once

#include "NumCpp/Coordinates/Euler.hpp"
#include "NumCpp/Coordinates/Orientation.hpp"
#include "NumCpp/Coordinates/ReferenceFrames/ECEF.hpp"
#include "NumCpp/Coordinates/Transforms/NEDRollPitchYawToECEFEuler.hpp"

namespace nc::coordinates::transforms
{
    /**
     * @brief Converts ENU body roll/pitch/yaw to ECEF euler angles
     *
     * @param location: the ecef location
     * @param orientation: ned euler angles
     * @return Orientation
     */
    [[nodiscard]] inline Euler ENURollPitchYawToECEFEuler(const reference_frames::ECEF& location,
                                                          const Orientation&            orientation) noexcept
    {
        const auto nedOrientation = Orientation{ orientation.pitch, orientation.roll, -orientation.yaw };
        const auto nedEuler       = NEDRollPitchYawToECEFEuler(location, nedOrientation);
        return { nedEuler.theta, nedEuler.psi, -nedEuler.phi };
    }
} // namespace nc::coordinates::transforms
