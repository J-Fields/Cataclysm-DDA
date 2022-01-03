#pragma once
#ifndef CATA_TESTS_STRINGMAKER_H
#define CATA_TESTS_STRINGMAKER_H

#include "cuboid_rectangle.h"
#include "cata_catch.h"

// StringMaker specializations for Cata types for reporting via Catch2 macros

class item;
struct point;
struct rl_vec2d;
class cata_variant;
class time_duration;
class time_point;
struct talk_response;

namespace Catch
{

template<> template<> std::string StringMaker<item>::convert( const item & );
extern template struct StringMaker<item>;
template<> template<> std::string StringMaker<point>::convert( const point & );
extern template struct StringMaker<point>;
template<> template<> std::string StringMaker<rl_vec2d>::convert( const rl_vec2d & );
extern template struct StringMaker<rl_vec2d>;
template<> template<> std::string StringMaker<cata_variant>::convert( const cata_variant & );
extern template struct StringMaker<cata_variant>;
template<> template<> std::string StringMaker<time_duration>::convert( const time_duration & );
extern template struct StringMaker<time_duration>;
template<> template<> std::string StringMaker<time_point>::convert( const time_point & );
extern template struct StringMaker<time_point>;
template<> template<> std::string StringMaker<talk_response>::convert( const talk_response & );
extern template struct StringMaker<talk_response>;

template<typename T>
struct StringMaker<string_id<T>> {
    static std::string convert( const string_id<T> &i ) {
        return string_format( "string_id( \"%s\" )", i.str() );
    }
};

template<typename T>
struct StringMaker<int_id<T>> {
    static std::string convert( const int_id<T> &i ) {
        return string_format( "int_id( \"%s\" )", i.id().str() );
    }
};

template<typename Point>
struct StringMaker<rectangle<Point>> {
    static std::string convert( const rectangle<Point> &r ) {
        return string_format( "[%s-%s]", r.p_min.to_string(), r.p_max.to_string() );
    }
};

template<typename Tripoint>
struct StringMaker<cuboid<Tripoint>> {
    static std::string convert( const cuboid<Tripoint> &b ) {
        return string_format( "[%s-%s]", b.p_min.to_string(), b.p_max.to_string() );
    }
};

} // namespace Catch

#endif // CATA_TESTS_STRINGMAKER_H
