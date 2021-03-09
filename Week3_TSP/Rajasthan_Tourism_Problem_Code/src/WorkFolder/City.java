package WorkFolder;

public class City {
	
	private double longitude;
	private double latitude;
	private String city_name;
	
	 public City(double latitude,double longitude,String city_name)
	 {
		 this.longitude=longitude;
		 this.latitude=latitude;
		this.city_name=city_name;
	 }
	 
	 public  String getCity_Name()
	 {
		 return city_name;
	 }
	 public double getLatitude()
	 {
		 return latitude;
	 }
	
	 public double getLongitude()
	 {
		 return longitude;
	 }
	
	 
	 /// Using Eulidian Algorithm Calculate  Distance between two node/vertex.
	 /// x=sqrt((x1-x2)^2+(y1-y2)^2).
	 public double  PathCost(City city)
	 {
		 double x=Math.abs(city.getLatitude()-this.latitude);
		 double y=Math.abs(city.getLongitude()-this.longitude);
		double dist=Math.sqrt((x*x)+(y*y)); 
		
		 return dist;
	 }
	 
	 public String toString()
	 {
		 return this.city_name;
	 }
}

