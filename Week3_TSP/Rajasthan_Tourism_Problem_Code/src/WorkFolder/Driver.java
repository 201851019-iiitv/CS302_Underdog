package WorkFolder;

import java.util.ArrayList;
import java.util.Arrays;

public class Driver {

	
	public ArrayList<City>Rajastan_Cities=new ArrayList<City>(Arrays.asList(
			new City(25.702503034283787, 73.58152248534205, "City Palace"),
			new City(27.665607356096267, 76.13035074255151, "Amber Palace"),
			new City(27.89888431960082, 75.07566318784414, "Hawa Mahal"),
			new City(26.49179507068974, 74.28464752181362, "Chittorgarh Fort"),
			new City(27.74342192499812, 73.22995996710627, "Jaswant Thada"),
			new City(28.59569358526302, 76.56980389034625, "Jaigarh Fort"),
			new City(24.5976062757075, 73.67966285529258, "Maharana Pratap Memorial"),
			new City(24.59349746222666, 73.63965924180238, "Sajjangarh Monsoon Palace"),
			new City(29.287913803748992, 76.13035074255151, "Bhangarh Fort"),
			new City(26.89245423532142, 75.81553157254318, "Birla Temple Jaipur"),
			new City(26.911833790980342, 75.8194553111577, "Albert Hall Museum"),
			new City(27.821180947322215, 76.21824137211046, "Ranthambore National Park"),
			new City(26.924991563302612, 75.82452781115796, "Jantar Mantar Jaipur"),
			new City(27.197559319676053, 76.39402263122835, "Ranthambore Fort"),
			new City(28.74991940396533, 76.04246011299257, "Jal Mahal"),
			new City(27.19755931967608, 73.58152248534205, "Kumbhalgarh Fort"),
			new City(25.860786617456906, 72.43894430107575, "Dilwara Temples"),
			new City(29.134487314536173, 70.24167856210207, "The Thar Heritage Museum"),
			new City(28.90391780739106, 77.09714766769993, "Sariska Tiger Reserve"),
			new City(24.267605308786163, 74.00025745250876, "Dhebar Lake")		
			
			));
	
	
	public static void main(String[] args)
	{
		
		Driver driver=new Driver();
		Route route =new Route(driver.Rajastan_Cities);
		driver.printHeading(route);
		Simulated_Annealing sa=new Simulated_Annealing();
		sa.FindRoute(Simulated_Annealing.INTIAL_TEMP,route); // Intial Temp declare as 10000.
		
	}
	
	// Print a format in console.
	public void printHeading(Route route)
	{
	String Column1=" Route";	
	String remainHead="Distance |Temp | ProbFunc | Random Prob | Decision                 ";	
	int len=0;
	for(int i=0;i<route.getCities().size();i++)
	{
		len +=route.getCities().get(i).getCity_Name().length();
	}
	int arrlen=len+route.getCities().size()*2;
	int partiallen=(arrlen-Column1.length())/2;
	
	for(int i=0;i<partiallen;i++)
	{
		System.out.print(" ");
	}
	
	System.out.print(Column1);
	for(int i=0;i<partiallen;i++)
	{
		System.out.print(" ");
	}
	if(arrlen%2==0)
		System.out.print(" ");
	System.out.println(" | "+remainHead);
	len +=remainHead.length()+3;
	for(int i=0;i<len+route.getCities().size()*2;i++)
	{
		System.out.print("-");
	}
	System.out.println("");
		
		
	}

}
