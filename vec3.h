#ifndef VEC3_H
#define VEC3_H

class vec3 {
	public:
		double e[3];
		
		vec3() : e{0,0,0} {}
		vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}
		
		//allowing 3 values to be accessed as xyz
		double x() const { return e[0]; }
		double y() const { return e[1]; }
		double z() const { return e[2]; }
		
		//defining operators
		vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		double operator[](int i) const { return e[i]; }
		double& operator[](int i) { return e[i]; }
		
		//defining addition
		vec3& operator+=(const vec3& v) {
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];
			return *this;
		}
		
		//defining multiplication
		vec3& operator*=(double t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;
			return *this;
		}
		
		//defining division
		vec3& operator/=(double t) {
			return *this *= 1/t;
		}
		
		//defining length function
		double length() const {
			return std::sqrt(length_squared());
		}
		
		//defining length squared function
		double length_squared() const {
			return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
		}		
};

using point3 = vec3;

//vector utility functions

//outputting vec3 values
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

//vector addition
inline vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

//vector subtraction
inline vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

//vector multiplication
inline vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

//multiplication with an scalar value
inline vec3 operator*(double t, const vec3& v) {
	return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

//multiplication
inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

//division
inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

//dot product
inline double dot(const vec3& u, const vec3& v) {
	return u.e[0] * v.e[0]
		 + u.e[1] * v.e[1]
		 + u.e[2] * v.e[2];
}

//cross product
inline vec3 cross(const vec3& u, const vec3& v) {
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
				u.e[2] * v.e[0] - u.e[0] * v.e[2],
				u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

//normalise length to a unit vector
inline vec3 unit_vector(const vec3& v) {
	return v / v.length();
}

#endif