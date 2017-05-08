/** Interface for creating lambda */
interface ParallelogramProperty{

    public double getFields(double length, double width);

}

/** This class creates a shape of type Parallelogram */
public class Parallelogram implements Shape{ 

    /** Parallelogram length */
    private double length;

    /** Parallelogram width */
    private double width;

    /**
     * Constructor accepts a double for the length and a dounble for width, throws exception if data is not valid
     * @param length A positive double representing the length of the Parallelogram
     * @param width  A positive double representing the width of the Parallelogram
     * */
    public Parallelogram(double length, double width) throws MyException{
        
            if (length == 0 || width == 0)
                throw new MyException("Values for length or width of the Paralellogram cannot be equal to zero. The values passed: " + length + ", " + width); 
            if (length < 0  || width < 0 )
                throw new MyException("Values for length or width of the Paralellogram cannot be negative. The values passed: " + length + ", " + width);  
            if (length > 0  && width > 0 ){
                this.length = length;
                this.width  = width;
            }
        
    }

    /**
     * Getting the perimeter of the Parallelogram
     * @return a double indicating the perimeter of the shape
     * */
    public double getPerimeter() {
       
       ParallelogramProperty perimeter = (length, width) ->
        {
            /** result of the lambda */
            double result;

            result = (2 * this.length) + (2 * this.width);

            return result;
        };
        return perimeter.getFields(this.length, this.width);
    }

    /**
     * Returning a string of the variable in the Parallelogram
     * @return a String indicating the length and width of the Parallelogram + its perimeter
     * */
    @Override
    public String toString(){
       return String.format("Parallelogram {w=%.2f, l=%.2f} perimeter=%.2f", this.width, this.length, this.getPerimeter());
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
     * @return a boolean indicating whether the Parallelograms are equal
     * */
    @Override
    public boolean equals(Object object){
      if (this == object)
            return true;
        if (object == null)
            return false;
        if (getClass() != object.getClass())
            return false;
        Parallelogram other = (Parallelogram) object;
        if (this.length != other.length && this.width != other.width)
            return false;
        return true;
    }

}