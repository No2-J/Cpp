#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <conio.h>
using namespace std;

#define MAX_SHAPES 10

inline int Abs(int x) { return x > 0 ? x : -x; }
inline int Max(int x, int y) { return x > y ? x : y; }
inline int Round(double x) { return (int)(x + 0.5); }

class Point {
private:
    int x, y;
    string color;
public:
    Point(int xx = 0, int yy = 0, const string& c = ". ") : x(xx), y(yy), color(c) {}
    ~Point() {}

    void setPosition(int xx, int yy) { x = xx; y = yy; }
    int getX() const { return x; }
    int getY() const { return y; }
    string getColor() const { return color; }
    void move(int dx, int dy) { x += dx; y += dy; }
};
class ShapeCanvas {
private:
    string** grid;
    int width, height;
public:
    ShapeCanvas(int w, int h) : width(w), height(h) {
        grid = new string * [height];
        for (int i = 0; i < height; ++i)
            grid[i] = new string[width];
        clear(" ");
    }

    ~ShapeCanvas() {
        for (int i = 0; i < height; ++i)
            delete[] grid[i];
        delete[] grid;
    }

    void clear(const string& c = ". ") {
        for (int y = 0; y < height; ++y)
            for (int x = 0; x < width; ++x)
                grid[y][x] = c;
    }

    void draw(int x, int y, const string& c) {
        if (x >= 0 && y >= 0 && x < width && y < height)
            grid[y][x] = c;
    }
    void draw(const Point& pt) {
        draw(pt.getX(), pt.getY(), pt.getColor());
    }

    void display(const string& title = "<ShapeCanvas>") {
        system("cls");
        cout << "\t\t" << title << endl;
        for (int y = 0; y < height; ++y) {
            for (int x = 0; x < width; ++x)
                cout << grid[y][x];
            cout << endl;
        }
    }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

};

class Shape {
protected:
    Point p;
public:
    Shape(int x = 0, int y = 0, const string& c = "* ") : p(x, y, c) {}
    virtual ~Shape() {}

    virtual void move(int dx, int dy) { p.move(dx, dy); }

    virtual bool isInside(ShapeCanvas& canvas, int dx, int dy) const = 0;
    virtual void draw(ShapeCanvas& canvas) = 0;
};

class Line : public Shape {
protected:
    Point q;
public:
    Line(int x1, int y1, int x2, int y2, const string& sym = "# ") : Shape(x1, y1, sym), q(x2, y2, sym) {}
    ~Line() {}

    void move(int dx, int dy) override {
        p.move(dx, dy);
        q.move(dx, dy);
    }

    bool isInside(ShapeCanvas& canvas, int dx, int dy) const override {
        int len = Max(Abs(q.getX() - p.getX()), Abs(q.getY() - p.getY()));
        double x = p.getX() + dx, y = p.getY() + dy;
        double dx1 = (q.getX() - p.getX()) / (double)len;
        double dy1 = (q.getY() - p.getY()) / (double)len;

        for (int i = 0; i <= len; ++i) {
            int px = Round(x), py = Round(y);
            if (px < 0 || py < 0 || px >= canvas.getWidth() || py >= canvas.getHeight())
                return false;
            x += dx1; y += dy1;
        }
        return true;
    }

    void draw(ShapeCanvas& canvas) override {
        int len = Max(Abs(q.getX() - p.getX()), Abs(q.getY() - p.getY()));
        double x = p.getX(), y = p.getY();
        double dx = (q.getX() - p.getX()) / (double)len;
        double dy = (q.getY() - p.getY()) / (double)len;

        for (int i = 0; i <= len; ++i) {
            canvas.draw(Point(Round(x), Round(y), p.getColor()));
            x += dx; y += dy;
        }
    }
};

class HLine : public Line {
public:
    HLine(int x, int y, int len, const string& sym = "- ") : Line(x, y, x + len, y, sym) {}
    ~HLine() {}

};

class VLine : public Line {
public:
    VLine(int x, int y, int len, const string& sym = "| ") : Line(x, y, x, y + len, sym) {}
    ~VLine() {}
};

class Rect : public Shape {
protected:
    int w, h;

public:
    Rect(int x, int y, int ww, int hh, const string& sym = "~ ") : Shape(x, y, sym), w(ww), h(hh) {}
    ~Rect() {}

    bool isInside(ShapeCanvas& canvas, int dx, int dy) const override {
        return p.getX() + dx >= 0 && p.getY() + dy >= 0 &&
            p.getX() + w + dx < canvas.getWidth() &&
            p.getY() + h + dy < canvas.getHeight();
    }

    void draw(ShapeCanvas& canvas) override {
        Line top(p.getX(), p.getY(), p.getX() + w, p.getY(), p.getColor());
        Line bottom(p.getX(), p.getY() + h, p.getX() + w, p.getY() + h, p.getColor());
        Line left(p.getX(), p.getY(), p.getX(), p.getY() + h, p.getColor());
        Line right(p.getX() + w, p.getY(), p.getX() + w, p.getY() + h, p.getColor());

        top.draw(canvas); bottom.draw(canvas);
        left.draw(canvas); right.draw(canvas);
    }

};
class Square : public Rect {
public:
    Square(int x, int y, int size, const string& sym = "* ") : Rect(x, y, size, size, sym) {}
    ~Square() {}
};
class Circle : public Shape {
private:
    int r;

public:
    Circle(int x, int y, int rr, const string& sym = "o ") : Shape(x, y, sym), r(rr) {}
    ~Circle() {}

    bool isInside(ShapeCanvas& canvas, int dx, int dy) const override {
        int x = p.getX() + dx, y = p.getY() + dy;
        return x - r >= 0 && x + r < canvas.getWidth() && y - r >= 0 && y + r < canvas.getHeight();
    }

    void draw(ShapeCanvas& canvas) override {
        Line(p.getX(), p.getY(), p.getX(), p.getY() + r, p.getColor());
        Line(p.getX(), p.getY(), p.getX(), p.getY() - r, p.getColor());
        Line(p.getX(), p.getY(), p.getX() + r, p.getY(), p.getColor());
        Line(p.getX(), p.getY(), p.getX() - r, p.getY(), p.getColor());
    }

};

class Editor {
private:
    ShapeCanvas canvas;
    Shape* shapes[MAX_SHAPES];
    int shapeCount;
public:
    Editor(int w = 30, int h = 30) : canvas(w, h), shapeCount(0) {
        for (int i = 0; i < MAX_SHAPES; ++i)
            shapes[i] = nullptr;
    }
    ~Editor() {
        clearShapes();
    }
    void clearShapes() {
        for (int i = 0; i < shapeCount; ++i) {
            delete shapes[i];
            shapes[i] = nullptr;
        }
        shapeCount = 0;
    }

    void addShape(Shape* shape) {
        if (shapeCount < MAX_SHAPES) {
            shapes[shapeCount++] = shape;
        }
    }

    void moveAll(int dx, int dy) {
        for (int i = 0; i < shapeCount; ++i) {
            if (!shapes[i]->isInside(canvas, dx, dy))
                return;
        }
        for (int i = 0; i < shapeCount; ++i)
            shapes[i]->move(dx, dy);
    }

    void drawAll(const string& title = "Graphic Editor") {
        canvas.clear();
        for (int i = 0; i < shapeCount; ++i)
            shapes[i]->draw(canvas);
        canvas.display(title);
    }

    void removeShape(int index) {
        if (index >= 0 && index < shapeCount) {
            delete shapes[index];
            for (int i = index; i < shapeCount - 1; ++i)
                shapes[i] = shapes[i + 1];
            shapeCount--;
        }
    }

    void setupShapes() {
        addShape(new Line(1, 1, 15, 4, "# "));
        addShape(new Rect(18, 15, 8, 4, "~ "));
        addShape(new Square(19, 5, 5, "* "));
        addShape(new HLine(1, 19, 10, "@ "));
        addShape(new VLine(16, 1, 18, "| "));
        addShape(new Circle(5, 12, 5, "o "));
    }

    void run() {
        setupShapes();
        drawAll();
        cout << "Enter to move (ESC for exit..)";
        while (true) {
            int key = _getch();
            if (key == 224) { // Arrow keys
                int arrow = _getch();
                int dx = 0, dy = 0;
                switch (arrow) {
                case 72: dy = -1; break; // Up
                case 80: dy = 1; break;  // Down
                case 75: dx = -1; break; // Left
                case 77: dx = 1; break;  // Right
                }
                moveAll(dx, dy);
                drawAll();
                cout << "Enter to move (ESC for exit..)";
            }
            else if (key == 27) {
                break;
            }
        }
    }

};
