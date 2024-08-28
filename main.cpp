/*
Задание 2. Иерархия геометрических фигур
Что нужно сделать
Спроектируйте иерархию классов различных фигур: круг, квадрат, равносторонний треугольник, прямоугольник.
Для всех этих фигур есть общие поля-данные — это координаты их центра и условный цвет фигуры: красный, синий или зелёный.
Для отдельных фигур есть и уникальные параметры: радиус для круга, длина ребра для квадрата и равностороннего треугольника, 
ширина и высота для прямоугольника. Все данные — это вещественные числа с удвоенной точностью.
Для каждой из фигур требуется определить метод нахождения площади фигуры, а также метод нахождения прямоугольника, описывающего 
фигуру полностью (он может быть больше зоны фигуры, но не меньше).
Для лучшего понимания задачи приведена иллюстрация. На ней разными цветами помечены площади фигур, а пунктиром изображены прямоугольники, 
описывающие фигуры.

Для теста предусмотрите ввод пользователем команд: circle, square, triangle, rectangle, соответствующих фигурам. Команды должны получать 
параметры фигур и выводить их цвет, площадь и описывающий прямоугольник с координатами.

Советы и рекомендации
Для цвета фигуры вы можете использовать собственный тип enum, в котором может содержаться и константа отсутствия цвета — None.
Площадь треугольника считается как length * length * std::sqrt(3) / 4; где length — сторона. Площадь круга — как atan(1) * 4 * radius;
Геометрические формулы вы можете найти в интернете.

Что оценивается
Элегантность выстроенной иерархии классов. Корректность работы методов вычислений для фигур важна, но не столь принципиальна.
*/

#include <iostream>
#include <cmath>


struct coordinates
{
    double x;
    double y;
};

enum color_figure {
    None,
    Red,
    Blue,
    Green
};


class Figure{
public:
    coordinates center;
    color_figure color;

};

class Circle: public Figure{
    double radius;

    public:
    Circle(coordinates in_center, color_figure in_color, double in_radius){
        center = in_center;
        color = in_color;
        radius = in_radius;
    }

    void area(){
        std::cout << "Area circle: " << atan(1) * 4 * radius << std::endl;
    }

    void describing_rectangle(){
        coordinates left_up;
        coordinates left_down;
        coordinates right_up;
        coordinates right_down;

        left_up.x = center.x - radius;
        left_up.y = center.y + radius;
        right_up.x = center.x + radius;
        right_up.y = center.y + radius;
        left_down.x = center.x - radius;
        left_down.y = center.y -radius;
        right_down.x = center.x + radius;
        right_down.y = center.y - radius;

        std::cout << "Rectangle coordinates: " << std::endl;
        std::cout << "(" << left_up.x << ", " << left_up.y << ")" << std:: endl;
        std::cout << "(" << right_up.x << ", " << right_up.y << ")" << std:: endl;
        std::cout << "(" << left_down.x << ", " << left_down.y << ")" << std:: endl;
        std::cout << "(" << right_down.x << ", " << right_down.y << ")" << std:: endl;
    }
};

class Square: public Figure{
    double length_side;

public:
    Square(coordinates in_center, color_figure in_color, double in_length_side){
        center = in_center;
        color = in_color;
        length_side = in_length_side;
    }

    void area(){
        std::cout<< "Area square: " << length_side*length_side << std::endl;
    }

    void describing_rectangle(){
        coordinates left_up;
        coordinates left_down;
        coordinates right_up;
        coordinates right_down;

        left_up.x = center.x - length_side / 2;
        left_up.y = center.y + length_side / 2;
        right_up.x = center.x + length_side /2;
        right_up.y = center.y + length_side / 2;
        left_down.x = center.x - length_side / 2;
        left_down.y = center.y - length_side / 2;
        right_down.x = center.x + length_side / 2;
        right_down.y = center.y - length_side / 2;

        std::cout << "Rectangle coordinates: " << std::endl;
        std::cout << "(" << left_up.x << ", " << left_up.y << ")" << std:: endl;
        std::cout << "(" << right_up.x << ", " << right_up.y << ")" << std:: endl;
        std::cout << "(" << left_down.x << ", " << left_down.y << ")" << std:: endl;
        std::cout << "(" << right_down.x << ", " << right_down.y << ")" << std:: endl;
    }
};

class Triangle: public Figure{
    double length_side;

public:
    Triangle(coordinates in_center, color_figure in_color, double in_length_side){
        center = in_center;
        color = in_color;
        length_side = in_length_side;
    }

    void area(){
        std::cout << "Area triangle: " << length_side * length_side * std::sqrt(3) / 4 << std:: endl;
    }

    void describing_rectangle(){
        coordinates left_up;
        coordinates left_down;
        coordinates right_up;
        coordinates right_down;

        left_up.x = center.x - length_side / 2;
        left_up.y = center.y + std::sqrt(3*length_side*length_side)/4;
        right_up.x = center.x + length_side /2;
        right_up.y = center.y + std::sqrt(3*length_side*length_side)/4;
        left_down.x = center.x - length_side / 2;
        left_down.y = center.y - std::sqrt(3*length_side*length_side)/4;
        right_down.x = center.x + length_side / 2;
        right_down.y = center.y - std::sqrt(3*length_side*length_side)/4;

        std::cout << "Rectangle coordinates: " << std::endl;
        std::cout << "(" << left_up.x << ", " << left_up.y << ")" << std:: endl;
        std::cout << "(" << right_up.x << ", " << right_up.y << ")" << std:: endl;
        std::cout << "(" << left_down.x << ", " << left_down.y << ")" << std:: endl;
        std::cout << "(" << right_down.x << ", " << right_down.y << ")" << std:: endl;
    }
};

class Rectangle: public Figure{
    double height;
    double width;

public:
    Rectangle(coordinates in_center, color_figure in_color, double in_height, double in_width){
        center = in_center;
        color = in_color;
        height = in_height;
        width = in_width;
    }

    void area(){
        std::cout<< "Area rectangle: " <<  height*width << std::endl;
    }

    void describing_rectangle(){
        coordinates left_up;
        coordinates left_down;
        coordinates right_up;
        coordinates right_down;

        left_up.x = center.x - width / 2;
        left_up.y = center.y + height / 2;
        right_up.x = center.x + width /2;
        right_up.y = center.y + height / 2;
        left_down.x = center.x - width / 2;
        left_down.y = center.y - height / 2;
        right_down.x = center.x + width / 2;
        right_down.y = center.y - height / 2;

        std::cout << "Rectangle coordinates: " << std::endl;
        std::cout << "(" << left_up.x << ", " << left_up.y << ")" << std:: endl;
        std::cout << "(" << right_up.x << ", " << right_up.y << ")" << std:: endl;
        std::cout << "(" << left_down.x << ", " << left_down.y << ")" << std:: endl;
        std::cout << "(" << right_down.x << ", " << right_down.y << ")" << std:: endl;
    }
};

int main(){
    std::cout << "Enter command: ";
    std::string command;
    std::cin >> command;

    if (command == "circle"){
        std::cout << "Enter circle coordinates of the center (x y): ";
        coordinates circle_center_coordinates;
        std::cin >> circle_center_coordinates.x;
        std::cin >> circle_center_coordinates.y;
        
        std::cout << "Enter circle color: ";
        color_figure circle_color;
        std::string enter_color;
        std::cin >> enter_color;
        if (enter_color == "Blue")
            circle_color = Blue;
        else if (enter_color == "Red")
            circle_color = Red;
        else if (enter_color == "Green")
            circle_color = Green;
        else
            circle_color = None;
        
        std::cout << "Enter circle radius: ";
        double circle_radius;
        std::cin >> circle_radius;

        Circle circle(circle_center_coordinates, circle_color, circle_radius);
        circle.area();
        circle.describing_rectangle(); 
    }
    else if (command == "square"){
        std::cout << "Enter square coordinates of the center (x y): ";
        coordinates square_center_coordinates;
        std::cin >> square_center_coordinates.x;
        std::cin >> square_center_coordinates.y;
        
        std::cout << "Enter square color: ";
        color_figure square_color;
        std::string enter_color;
        std::cin >> enter_color;
        if (enter_color == "Blue")
            square_color = Blue;
        else if (enter_color == "Red")
            square_color = Red;
        else if (enter_color == "Green")
            square_color = Green;
        else
            square_color = None;
        
        std::cout << "Enter square length side: ";
        double length_side;
        std::cin >> length_side;

        Square square(square_center_coordinates, square_color, length_side);
        square.area();
        square.describing_rectangle(); 
    }
    else if (command == "triangle"){
        std::cout << "Enter triangle coordinates of the center (x y): ";
        coordinates triangle_center_coordinates;
        std::cin >> triangle_center_coordinates.x;
        std::cin >> triangle_center_coordinates.y;
        
        std::cout << "Enter triangle color: ";
        color_figure triangle_color;
        std::string enter_color;
        std::cin >> enter_color;
        if (enter_color == "Blue")
            triangle_color = Blue;
        else if (enter_color == "Red")
            triangle_color = Red;
        else if (enter_color == "Green")
            triangle_color = Green;
        else
            triangle_color = None;
        
        std::cout << "Enter triangle length side: ";
        double length_side;
        std::cin >> length_side;

        Triangle triangle(triangle_center_coordinates, triangle_color, length_side);
        triangle.area();
        triangle.describing_rectangle(); 
    }
    else if (command == "rectangle"){
        std::cout << "Enter rectangle coordinates of the center (x y): ";
        coordinates rectangle_center_coordinates;
        std::cin >> rectangle_center_coordinates.x;
        std::cin >> rectangle_center_coordinates.y;
        
        std::cout << "Enter rectangle color: ";
        color_figure rectangle_color;
        std::string enter_color;
        std::cin >> enter_color;
        if (enter_color == "Blue")
            rectangle_color = Blue;
        else if (enter_color == "Red")
            rectangle_color = Red;
        else if (enter_color == "Green")
            rectangle_color = Green;
        else
            rectangle_color = None;
        
        std::cout << "Enter rectangle hight: ";
        double hight;
        std::cin >> hight;

        std::cout << "Enter rectangle width: ";
        double width;
        std::cin >> width;

        Rectangle rectangle(rectangle_center_coordinates, rectangle_color, hight,width);
        rectangle.area();
        rectangle.describing_rectangle(); 
    }

}