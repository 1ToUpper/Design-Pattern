#include "DecoratorPattern-8.h"

using namespace std;

int main()
{
    std::shared_ptr<Ractangle> ract_shaperact_shape = std::make_shared<Ractangle>();
    std::shared_ptr<Circle> cir_shape = std::make_shared<Circle>();
    ract_shaperact_shape->draw();
    cir_shape->draw();
    std::cout << "========================" << std::endl;
    std::shared_ptr<RedShapeDecorator> red_decorator = std::make_shared<RedShapeDecorator>(cir_shape);
    std::shared_ptr<RedShapeDecorator> red_decorator_2 = std::make_shared<RedShapeDecorator>(ract_shaperact_shape);
    red_decorator->draw();
    red_decorator_2->draw();
    return 0;
}