int fnXRaisedN(int iX, int iN)
{
	if(iN == 1)
		return iX;
	else
		return iX * fnXRaisedN(iX, iN - 1);
}

int fnXRaisedN(int iX, int iN)
{
	int iLeft, iRight;
	
	if(iN == 1)
		return iX;
	else if(0 == iN%2)
	{
		iLeft = fnXRaisedN(iX, iNum/2);
		iRight = fnXRaisedN(iX, iNum/2);
		return iLeft * iRight;
	}
	else
	{
		iLeft = fnXRaisedN(iX, floor(iNum/2));
		iRight = fnXRaisedN(iX,floor(iNum/2));
		return iLeft * iRight * iX;
	}
	
}


		DO NOT TRY THESE PROGRAMS AT HOME
		THIS PROGRAM HAS BEEN WRITTEN BY PROFESSIONALS
		IN A CONTROLLED ENVIRONMENT
		
		NO ANIMALS WERE HARMED IN THIS EXERCISE
		
		
		
		
		moodle.sit.ac.in/moodle
		
		
		username : 1si16cs046
		password : Change@1nce
		
		
		
		
		
		
		
		
		
		
		
		
		



