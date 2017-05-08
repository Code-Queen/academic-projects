/** Interface for creating lambda */
interface CircleProperty{

    double get(double radius);

}

/** This class creates a shape of type circle */
public class Circle implements Shape{ 

    /** circle radius */
    private double radius;


    /**
     * Constructor accepts an double for the radius, throws exception if data is not valid
     * @param radius A positive double representing the radius of the circle
     * */
    public Circle(double radius) throws MyException{

            if (radius == 0)
                throw new MyException("Radius of the Circle cannot be equal to zero. The value passed: "+ radius); 
            if (radius < 0)
                throw new MyException("Radius of the Circle cannot be negative. The value passed: "+ radius);  
            if (radius > 0)
                this.radius = radius;
    }

    /** 
     * Getting the radius of particular Circle
     * @param radius A positive double representing the radius of the circle
     * @param c CircleProperty interface indicating particular Circle
     * @return a double indicating the radius of the Circle
     * */
    public double circleValue(double radius, CircleProperty c){
        return c.get(radius);
    }
    /**
     * Getting the perimeter of the circle
     * @return a double indicating the perimeter of the shape
     * */
    public double getPerimeter() {
       CircleProperty perimeter = radius -> 2 * Math.PI * this.radius;
       return this.circleValue(this.radius, perimeter);
    }

    /**
     * Returning a string of the variable in the circle
     * @return a String indicating the radius of the circle + its perimeter
     * */
    @Override
    public String toString(){
        return String.format("Circle {r=%.2f} perimeter=%.2f", this.radius, this.getPerimeter());
       
    }

    /**
     * Unique hashCode
     * @return a unique integer hashCode
     * */
    @Override
    public int hashCode(){

        /** integer to generate hashcode */
        final int prime = 31;

        /** integer to generate hashcode */
        int result = 17;

        result = prime * result + new Double(this.radius).hashCode();
      
        return result;
    }

    /**
     * Equals function
     * @param object an object indicating an object to compare with 'this' object
     * @return a boolean indicating whether the circles are equal
     * */
    @Override
    public boolean equals(Object object){
      if (this == object)
            return true;
        if (object == null)
            return false;
        if (getClass() != object.getClass())
            return false;
        Circle other = (Circle) object;
        if (this.radius != other.radius)
            return false;
        return true;
    }

}