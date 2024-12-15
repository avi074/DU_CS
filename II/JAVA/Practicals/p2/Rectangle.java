package p2;

import p1.Shape;

public class Rectangle extends Shape {
    private float height, width;

    public Rectangle(float height, float width) {
        this.height = height;
        this.width = width;
    }

    public float getHeight() {
        return height;
    }

    public void setHeight(float height) {
        this.height = height;
    }

    public float getWidth() {
        return width;
    }

    public void setWidth(float width) {
        this.width = width;
    }

    @Override
    public float Area() {
        return (height * width);
    }

    public String toString() {
        return ("Height : " + height + "\nWidth : " + width);
    }
}
