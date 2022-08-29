#pragma once

// Using "Curiously Recurring Template Pattern" (https://www.fluentcpp.com/2017/05/12/curiously-recurring-template-pattern/)


template <typename Derived, template<typename...> class crtpType, typename... Args>
class CRTP {
protected:
    Derived& derived() { return static_cast<Derived&>(*this); }
    Derived const& derived() const { return static_cast<Derived const&>(*this); }
private:
    CRTP() = default;
    friend crtpType<Derived, Args...>;
};
