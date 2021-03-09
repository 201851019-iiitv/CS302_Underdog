package WorkFolder;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Route {

	private ArrayList<City>cities=new ArrayList<City>();
	
	
	// Adding route between nodes
	public Route(ArrayList<City>cities)
	{
		this.cities.addAll(cities);
		Collections.shuffle(this.cities);  // shuffle or permutate the nodes
	}
	
	public Route(Route route)
	{
		this.cities.addAll(route.cities);
	}
	
	// return cities name and all.
	public ArrayList<City> getCities()
	{
		return cities;
	}
	
	// find distance of two cities
	public double getTotalDist()
	{
		int cities_Size=this.cities.size();
		return (int)(this.cities.stream().mapToDouble(x ->
		{
			int city_Index=this.cities.indexOf(x);
			double a=0.0;
			if(city_Index<cities_Size-1)
				a=x.PathCost(this.cities.get(city_Index+1));
			return a;
		}).sum()+this.cities.get(cities_Size-1).PathCost(this.cities.get(0)));
		
		
	}
	
	public String getTotalStringDist()
	{
		String a=String.format("%.2f",this.getTotalDist());
		if(a.length()==7)
			a=""+a;
		return a;
		
	}
	
	public String toString()
	{
		return Arrays.toString(cities.toArray());
	}
	
			
}
