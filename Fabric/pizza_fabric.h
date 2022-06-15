#include <iostream>
#include <string>


namespace pf {
	class Pizza { //абстрактный класс продукта
	protected:
		std::string name;

	public:
		void prepare() {
			std::cout << name << " is preparing...\n";
		}

		void bake() {
			std::cout << "Baking for some time...\n";
		}

		void cut() {
			std::cout << "Cutting into circles...\n";
		}

		void box() {
			std::cout << "Placing into the box...\n";
		}

	protected:
		Pizza() {} //чтоб его не могли вызвать

	};

	class ChicagoCheesePizza : public Pizza {
	public:
		ChicagoCheesePizza() {
			name = "Chicago Style Deep Dish Cheese Pizza";
		}
	};


	class NYCheesePizza : public Pizza {
	public:
		NYCheesePizza() {
			name = "NY Style Sause and Cheese Pizza";
		}
	};

	class PizzaStore { //абстрактный класс производителя
	public:
		Pizza* orderPizza(std::string type) {
			Pizza* pizza;

			pizza = createPizza(type);
			if (pizza == nullptr) {
				std::cout << "Sorry, we don't have such pizza\n";
				return nullptr;
			}

			pizza->prepare();
			pizza->bake();
			pizza->cut();
			pizza->box();

			return pizza;
		}	

	protected:
		virtual Pizza* createPizza(std::string type) = NULL;
	};
	
	class NYStore : public PizzaStore { //NY пиццерия
	public:
		Pizza* createPizza(std::string type) override {
			if (type == "cheese")
				return new NYCheesePizza;
			else
				return nullptr;
		}

	};

	class ChicagoStore : public PizzaStore {
	public:
		Pizza* createPizza(std::string type) override {
			if (type == "cheese")
				return new ChicagoCheesePizza;
			else
				return nullptr;
		}
	};
}