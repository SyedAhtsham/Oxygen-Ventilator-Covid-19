


#include <iostream>
#include<math.h>
#include<stdio.h>
using namespace std;


//constants declaration and initialiazatoin
const float PRESSURE = 10000000;           //Constant for Pressure i.e., 10MPa
const float PI = 3.142;                     //Constant for Pi i.e., 3.142


//Input Funcitons Prototypes
float inputRadius();
float inputLength();
float inputTemperature();


//Conversion Funcitons Prototypes
float convertToMeter(float );
float convertToKelvin(float );
float convertToLperMin(float);


//Calculations Funcitons Prototypes
float calculateArea(float );
float calculateViscosity(float );
float calculateFlowRate( float, float, float);


//display the output
void displayData(float, float, float, float);



///////////////////////////////////////////
//Main function//////
//////////////////////////////////////////
int main() {
    
    char flag;  
    
    do{
        
    float radius_in_milimeter = inputRadius();
    float radius_in_meter = convertToMeter(radius_in_milimeter);


    float length_in_meter = inputLength();

    float temperature_in_Celcius = inputTemperature();
    float temperature_in_Kelvin = convertToKelvin(temperature_in_Celcius);


    
    float flowRateIn_L_per_min = calculateFlowRate(calculateArea(radius_in_meter), calculateViscosity(temperature_in_Kelvin), length_in_meter);

        
    displayData(flowRateIn_L_per_min, length_in_meter, radius_in_milimeter, temperature_in_Celcius);


        cout<<"Do you wish to perform another set of calculations <y/n>?";
        cin>>flag;

    }while(flag =='y'||flag=='Y');          //to check whether the user wants to do another calculation or not

    cout<<endl;
    
    return 0;
}





//Function to convert radius in milimeter to radius in meter
float convertToMeter(float radius)
{
    return radius*0.001;          //multipyling by 10^-3 to to convert it to meter
}



//Function to convert the temperature from Celcius to Kelvin
float convertToKelvin(float tempC)
{
    return tempC+273.15;           //adding 273.15 into the temperature in celcius to make it kelvin
}



//Function to calculate the area of the hose pipe
float calculateArea(float radius)
{
    return PI*radius*radius;            //since A = PI*r^2, this formula is used to calculate the area and return the value
}




//Function to calculate the viscosity of the oxygen, temperature in kelvin is taken as parameter to the function
float calculateViscosity(float tempK)
{
    return (-6.212 * pow(10, -11))*(pow(tempK,2)) + (8.894 * pow(10, -8))*(tempK) - (5.672 * pow(10, -7));      //viscosity calculation formula is used and the value(result
}                                                                                                               //is returned




//Function to convert the flow rate from m^3/sec to Liter/min
float convertToLperMin(float flowRate)
{
    flowRate = flowRate*0.001*60000;        //multiplying the value with 10^-3 and 60000
    return flowRate;                        //returning the result in L/min

}




//Function to calculate the flowrate by taking parameters in the standard SI Units
float calculateFlowRate( float area, float viscosity, float length)
{
    
    float flowRate = (PRESSURE*pow(area, 2))/(8*PI*viscosity*length);       // formula of the Flow rate calculation
    
    flowRate = convertToLperMin(flowRate);                      //converting the flow rate into the L/min from m^3/sec
    
    return flowRate;                //returning the flow rate in L/min
    
}




//Function to take the input of the radius of the hose pipe, and it'll validate the input as well
float inputRadius()
{
    float radiusIn_mm;          //declaring the local variables
    int tempRadius;
    
    do{
    cout<<"Please enter the hose radius <from 0.20 to 3.00 mm>: ";
    cin>>radiusIn_mm;
    
    tempRadius = radiusIn_mm*10;                    //assigning value to temporary variable for the purpose of input validation (multiples of 0.2)
    

    }while(((tempRadius%2)!=0) || !((radiusIn_mm >= 0.2) && (radiusIn_mm <= 3)));       //checking whether the input is multiple of 0.2 and it's in range 0.2-3.00
    
    return radiusIn_mm;         //returning the valid radius
}





//Function to get Length of the hose pipe and it'll validate the input whether it's is multiple of 0.3 and it's in range 0.3-6.00
float inputLength()
{
    float length;           //declaring the local variables
    int tempLength;
    
    do{
    cout<<"Please enter the hose length <from 0.30 to 6.00 m>: ";
    cin>>length;
    
    tempLength = length*10;                         //assigning value to temporary variable for the purpose of input validation (multiples of 0.2)
    

    }while(((tempLength%3)!=0) || !((length >= 0.3) && (length <= 6))); //checking whether the input is multiple of 0.3 and it's in range 0.3-6.00
    
    return length;              //returning the valid length
}





//Function to take input of temperature and validate the input on the basis of range  -25C-50C
float inputTemperature()
{
    
    float temperature;

    do{
    cout<<"Please enter the temperature <from -25.00 to 50.00 degrees Celcius>: ";
    cin>>temperature;
                    
    }while( !((temperature >= -25) && (temperature <= 50)));        //checking whether the input is in range -25-50C

    return temperature;             //returning the valid temperature in range
}





//Function to display the data:length, radius, temperature, Flow rate, and whether the flow rate is in required range or not
void displayData(float flowrate, float length, float radius, float temperature)
{
    cout<<endl;
     cout<<endl;
          cout<<endl;
          cout<<"For a hose length of "<<length<<" m, with a radius of "<<radius<<" mm, at "<<temperature<<"C:";
            
            cout<<endl;
            
            cout<<"||*********************************************    Minimum Flow Rate. 5.00 L/min"<<endl;
            
            cout<<"||";
       for(float i=0; i<flowrate; i+=.11)
            {                                   //For loop to display the flowrate on x-axis
                cout<<"#";                      //SCALE:    0.11 L/min =  1"#"  on x-axis
            }
            
            cout<<"    Flow Rate. "<<flowrate<<" L/min"<<endl;
            
            
            cout<<"||************************************************************************    Maximum Flow Rate. 8.00 L/min"<<endl;

          cout<<endl;
          
    
    //if statement to check whether the flow rate is below, above or is within the required range i.e., 5.00 to 8.00 L/min
    if(flowrate>=5 && flowrate<=8)          //within the range
    {
        
        cout<<"This is within the required range of 5.00 to 8.00 L/min."<<endl;
    }
      
    else if(flowrate<5){                    //below the range
        
        cout<<"Flow Rate is below the required range of 5.00 to 8.00 L/min."<<endl;
    }
    
    else                //above the required range
    {
        cout<<"Flow Rate is above the required range of 5.00 to 8.00 L/min."<<endl;

    }
    
    cout<<endl;
    cout<<endl;
}
