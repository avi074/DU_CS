package P3;

import p1.Shape;

public class Circle extends Shape {
    private float radius;

    public Circle(float radius) {
        this.radius = radius;
    }

    public float getRadius() {
        return radius;
    }

    public void setRadius(float radius) {
        this.radius = radius;
    }

    @Override
    public float Area() {
        return (float) (Math.PI * radius * radius);
    }

    public String toString() {
        return ("radius : " + radius);
    }
}
