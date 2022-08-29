#pragma once

#include "Services.hpp"
#include "Controller.hpp"


class App {
public:
	void run();

private:
	Services _services;
	Controller _controller;
};
