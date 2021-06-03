#pragma once
#include <memory>

class WyborPlanu
{
public:
	virtual void WybierzPlan(int kalorie, int ilosc_dan) = 0;
};

class Miesny : public WyborPlanu
{
public:
	Miesny() {};
	void WybierzPlan(int kalorie, int ilosc_dan) override;
	static std::shared_ptr<WyborPlanu> wybierz_miesny();
};

class Wege : public WyborPlanu
{
public:
	Wege() {};
	void WybierzPlan(int kalorie, int ilosc_dan) override;
	static std::shared_ptr<WyborPlanu> wybierz_wege();
};
