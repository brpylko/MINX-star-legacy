/*
    MINX - A C++ Graphics and Input Wrapper Library
    Copyright (C) 2013  MINX Team

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

	*/
#ifndef VECTOR2_H_
#define VECTOR2_H_
namespace MINX
{
	/** A Vector that holds 2 components, X and Y.
	 */
	struct Vector2
	{
		/** Initializes the Vector2 with an x and a y component.
		 * @param x The x component of the Vector2.
		 * @param y The y component of the Vector2.
		 */

			Vector2(float x, float y);
		/** Adds 2 Vector2s.
		 * @param addTo the Vector2 to add.
		 */

			Vector2 operator+(const Vector2& addTo);
		/** Subtracts a Vector2 from another.
		 * @param subtractFrom the Vector2 to subtract.
		 */

			Vector2 operator-(const Vector2& subtractFrom);
		/** "cross multiplies" 2 Vector2s.
		 * There are "'s there because you can't REALLY cross multiply a 2 dimensional vector.
		 * @param multiplyBy the Vector2 to "cross multiply" by.
		 */

			Vector2 crossMultiply(const Vector2& multiplyBy);
		/** Dot multiplies 2 Vector2s.
		 * @param multiplyBy the Vector2 to dot multiply by.
		 */

			float operator*(const Vector2& multiplyBy);
		/** Multiplies a Vector2 by a scalar.
		 * @param multiplyBy the scalar to multiply the length of the Vector2 by.
		 */

			Vector2 operator*(const float& multiplyBy);
		/** Negates a Vector2.
		 */

			Vector2 operator-()const;
		/** Tests equality between 2 Vector2s.
		 * @param compareTo the Vector2 to test equality with.
		 */

			bool operator==(const Vector2& compareTo);
		/** Tests inequality between 2 Vector2s.
		 * @param compareTo the Vector2 to test equality with.
		 */

			bool operator!=(const Vector2& compareTo);
		/** Returns the length of the Vector2.
		 */

			float length();
		/** Returns the length of the Vector2 squared.
		 * This is faster then squaring the result of length() because length() actually returns the square root of the mathematical result of the length squared.
		 */

			float lengthSquared();
		/** Returns a Vector2 of length 1 but the same direction as the current Vector2.
		 */

			Vector2 normalize();
		/** The X component of the Vector2.
		 */
		float X;
		/** The Y component of the Vector2.
		 */
		float Y;
	};
}
#endif
