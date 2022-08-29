#pragma once

#include "utils/algorithms/hash.hpp"


class Result {
public:
	constexpr Result(const std::string_view sv) : _result{ hash_djb2a(sv) } {}
	constexpr Result(const Result&) = default;

	constexpr bool operator==(const Result& rhs) { return _result == rhs._result; }

	constexpr bool succeeded() { return *this == Result{ "Success" }; }
	constexpr bool failed() { return !succeeded(); }

private:
	Hash _result;
};


constexpr Result SUCCESS{ "Success" };
constexpr Result FAILURE{ "Failure" };
