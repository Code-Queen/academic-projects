/** Interface for creating lambda */
interface TriangleProperty{

   public double getFields(double sideA, double sideB, double sideC);

}

/** This class creates a shape of type Triangle */
public class Triangle implements Shape{

    /** Triangle sideA */
    private double sideA;

    /** Triangle sideB */
    private double sideB;

    /** Triangle sideC */
    private double sideC;

    /**
     * Constructor accepts a double for the sideA and a dounble for sideB, a dounble for sideC, throws exception if data is not valid
     * @param sideA A positive double representing the sideA of the Triangle
     * @param sideB A positive double representing the sideB of the Triangle
     * @param sideC A positive double representing the sideC of the Triangle
     * */
    public Triangle(double sideA, double sideB, double sideC) throws MyException{  
        
            if (sideA == 0 || sideB == 0 || sideC == 0)
                throw new MyException("Values of the Triangle for sideA, sideB, sideC cannot be equal to zero. The values passed: " + sideA + ", " + sideB +", " + sideC); 
            if (sideA < 0  || sideB <  0 || sideC < 0 )
                throw new MyException("Values of the Triangle for sideA, sideB, sideC cannot be negative. The values passed: " + sideA + ", " + sideB +", " + sideC); 
            if ((sideA + sideB) < sideC || (sideA + sideC) < sideB || (sideC + sideB) < sideA ){
                throw new MyException("The sum of two sides of the Triangle must be greater than the third side. The values passed: " + sideA + ", " + sideB +", " + sideC);    
            } else if (sideA > 0  && sideB > 0 && sideC > 0 ){
                this.sideA  = sideA;
                this.sideB  = sideB;
                this.sideC  = sideC;
            }
        
    }

    /**
     * Getting the perimeter of the Triangle
     * @return a double indicating the perimeter of the shape
     * */
    public double getPerimeter() {
      
       TriangleProperty perimeter = (sideA, sideB, sideC) ->
        {
            /** result of the lambda */
            double result;

            result = this.sideA + this.sideB + this.sideC;

            return result;
        };
        return perimeter.getFields(this.sideA, this.sideB, this.sideC);
    }

    /**
     * Returning a string of the variable in the Triangle
     * @return a String indicating the sideA and sideB of the Triangle + its perimeter
     * */
    @Override
    public String toString(){
       return String.format("Triangle {sideA=%.2f, sideB=%.2f, sideC=%.2f} perimeter=%.2f", this.sideA, this.sideB, this.sideC, this.getPerimeter());
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

        result = prime * result + new Double(this.sideA).hashCode();
        result = prime * result + new Double(this.sideB).hashCode();
        result = prime * result + new Double(this.sideC).hashCode();

      
        return result;
    }

    /**
     * Equals function
     * @param object an object indicating an object to compare with 'this' object
     * @return a boolean indicating whether the Triangles are equal
     * */
    @Override
    public boolean equals(Object object){
      if (this == object)
            return true;
        if (object == null)
            return false;
        if (getClass() != object.getClass())
            return false;
        Triangle other = (Triangle) object;
        if (this.sideA != other.sideA && this.sideB != other.sideB && this.sideC != other.sideC)
            return false;
        return true;
    }

}