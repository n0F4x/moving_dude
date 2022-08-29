#include <functional>
#include <unordered_map>
#include <ranges>
#include "SFML/Window/Event.hpp"


typedef unsigned ID;


class Controller {
public:
	ID add(std::function<bool(const sf::Event&)> event_checker, std::function<void()> command) {
		_commands.try_emplace(++_lastId, event_checker, command);
		return _lastId;
	}
	void remove(ID id) {
		_commands.erase(id);
	}

	void handle_event(const sf::Event& event) const {
		for (const auto& [check, command] : _commands | std::views::values) {
			if (check(event)) {
				command();
			}
		}
	}
	
private:
	ID _lastId;
	std::unordered_map<ID, std::pair<std::function<bool(const sf::Event&)>, std::function<void()>>> _commands;
};
