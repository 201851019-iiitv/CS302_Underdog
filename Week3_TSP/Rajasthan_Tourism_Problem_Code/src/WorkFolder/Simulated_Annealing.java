package WorkFolder;

public class Simulated_Annealing {

	 static final double RATE_OF_COOLING=0.9;
	 static final double INTIAL_TEMP=10000.00;
	 static final double MIN_TEMP= 0.00001;
	
	// Adjacent Routes 
	private Route NeighbourPath(Route route)
	{
		int x1=0,x2=0;
		while(x1==x2)
		{
			x1=(int)(route.getCities().size()*Math.random());
			x2=(int)(route.getCities().size()*Math.random());
		}
		
		City city1=route.getCities().get(x1);
		City city2=route.getCities().get(x2);
		route.getCities().set(x2,city1);
		route.getCities().set(x1,city2);
		return route;
	}


	// Find the Adjacent Route
	public Route FindRoute(double intialTemp, Route route) {
		
		Route shortestRoute=new Route(route);
		Route AdjacentRoute;
		while(intialTemp>MIN_TEMP)
		{
			System.out.print(route +" | "+route.getTotalStringDist()+" | "+String.format("%.2f",intialTemp));
			AdjacentRoute=NeighbourPath(new Route(route));
			if(route.getTotalDist()<shortestRoute.getTotalDist())
			{
				shortestRoute=new Route(route);
			}
			if(acceptPath(route.getTotalDist(),AdjacentRoute.getTotalDist(),intialTemp))
			{
				route=new Route(AdjacentRoute);
			}
			intialTemp *=(1-RATE_OF_COOLING);
			
		}
		
		return shortestRoute;
		
	}
	
      // Check Adjacent path is lesser cost or it have a good probability .
	public boolean acceptPath(double currDist,double adjDist,double temp)
	{
		boolean accept=false;
		double acceptProb=1.00;
		String decision ="";
		boolean shortestDist=true;
		
		if(adjDist>=currDist)
		{
			acceptProb=Math.exp((currDist-adjDist)/temp);
			shortestDist=false;
		}
		
		double rand=Math.random();
		
		if(acceptProb>=rand)
		{
			accept=true;
		}
		if(shortestDist)
		{
			decision="Procced With Adjacent Route";
			
		}
		else if(accept)
		{
			decision="Proceed With some Probability Function";
		}
		else
		{
			decision="Stay on root node ";
		}
		System.out.println(" | "+String.format("%.2f",acceptProb)+" | "+String.format("%.2f",rand)+" | "+decision);
		
		
		
	
		return accept;
		
	}
	
	
}
