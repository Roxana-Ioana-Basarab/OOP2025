#include "Canvas.h"
#include <cmath>
#include <stdio.h>
#include <string.h>

Canvas::Canvas(int width, int height) : width(width), height(height) {
    matrix = new char* [height];
    for (int i = 0; i < height; i++) {
        matrix[i] = new char[width];
        for (int j = 0; j < width; j++) {
            matrix[i][j] = ' ';
        }
    }
}

void Canvas::SetPoint(int x, int y, char ch) {
    if (x >= 0 && x < width && y >= 0 && y < height && matrix[y][x]==' ') {
        matrix[y][x] = ch;
    }
}


/*void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int sx = (x1 < x2) ? 1 : (x1 > x2 ? -1 : 0);
    int sy = (y1 < y2) ? 1 : (y1 > y2 ? -1 : 0);

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        if(x1!=x2)
        x1 += sx;
        if(y1!=y2)
        y1 += sy; 
    }
}*/
//
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    while (true) {
        SetPoint(x1, y1, ch);
        if (x1 == x2 && y1 == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x1 += sx; }
        if (e2 < dx) { err += dx; y1 += sy; }
    }
}



void Canvas::DrawRect(int left, int top, int right, int bottom, char ch) {
    for (int i = left; i <= right; i++) {
        SetPoint(i, top, ch);
        SetPoint(i, bottom, ch);
    }
    for (int i = top; i <= bottom; i++) {
        SetPoint(left, i, ch);
        SetPoint(right, i, ch);
    }
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    for (int i = top; i <= bottom; i++) {
        for (int j = left; j <= right; j++) {
            SetPoint(j, i, ch);
        }
    }
}


//
void Canvas::DrawCircle(int x, int y, int ray, char ch) {
    int d = 3 - 2 * ray;
    int xc = 0, yc = ray;

    while (xc <= yc) {
        SetPoint(x + xc, y + yc, ch);
        SetPoint(x - xc, y + yc, ch);
        SetPoint(x + xc, y - yc, ch);
        SetPoint(x - xc, y - yc, ch);
        SetPoint(x + yc, y + xc, ch);
        SetPoint(x - yc, y + xc, ch);
        SetPoint(x + yc, y - xc, ch);
        SetPoint(x - yc, y - xc, ch);

        if (d < 0) {
            d += 4 * xc + 6;
        }
        else {
            d += 4 * (xc - yc) + 10;
            yc--;
        }
        xc++;
    }
}
//
void Canvas::FillCircle(int x, int y, int ray, char ch) {
    for (int i = -ray; i <= ray; i++) {
        for (int j = -ray; j <= ray; j++) {
            if (i * i + j * j <= ray * ray) {
                SetPoint(x + i, y + j, ch);
            }
        }
    }
}

void Canvas::Print() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf ("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

void Canvas::Clear() {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            matrix[i][j] = ' ';
        }
    }
}
