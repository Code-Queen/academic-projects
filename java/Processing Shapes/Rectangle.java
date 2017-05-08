/** Interface for creating lambda */
interface RectangleProperty{

    public double getFields(double length, double width);

}

/** This class creates a shape of type Rectangle */
public class Rectangle implements Shape{ 

    /** Rectangle length */
    private double length;

    /** Rectangle width */
    private double width;

    /**
     * Constructor accepts a double for the length and a dounble for width, throws exception if data is not valid
     * @param length A positive double representing the length of the Rectangle
     * @param width  A positive double representing the width of the Rectangle
     * */
    public Rectangle(double length, double width) throws MyException{
       
            if (length == 0 || width == 0)
                throw new MyException("Values for length or width of the Rectangle cannot be equal to zero. The values passed: " + length + ", " + width); 
            if (length < 0  || width < 0 )
                throw new MyException("Values for length or width of the Rectangle cannot be negative. The values passed: " + length + ", " + width);  
            if (length > 0  && width > 0 ){
                this.length = length;
                this.width  = width;
            }
    
    }

    /**
     * Getting the perimeter of the Rectangle
     * @return a double indicating the perimeter of the shape
     * */
    public double getPerimeter() {

        RectangleProperty perimeter = (length, width) ->
        {
            /** result of the lambda */
            double result;

            result = (2 * length) + (2 * width);

            return result;
        };
        return perimeter.getFields(this.length, this.width);
    }

    /**
     * Returning a string of the variable in the Rectangle
     * @return a String indicating the length and width of the Rectangle + its perimeter
     * */
    @Override
    public String toString(){
       return String.format("Rectangle {w=%.2f, l=%.2f} perimeter=%.2f", this.width, this.length, this.getPerimeter());
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

        result = prime * result + new Double(this.length).hashCode();
        result = prime * result + new Double(this.width).hashCode();  
      
        return result;
    }

    /**
     * Equals function
     * @param object an object indicating an object to compare with 'this' object
     * @return a boolean indicating whether the Rectangles are equal
     * */
    @Override
    public boolean equals(Object object){
      if (this == object)
            return true;
        if (object == null)
            return false;
        if (getClass() != object.getClass())
            return false;
        Rectangle other = (Rectangle) object;
        if (this.length != other.length && this.width != other.width)
            return false;
        return true;
    }

}