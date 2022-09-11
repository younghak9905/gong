package day2Project;

import java.util.Scanner;

public class Store {
	String code;
	String name;
	int price;
	int count;
	
	void read(int i,Scanner scan)
	{	count=i;
		code=scan.next();
		name=scan.next();
		price=scan.nextInt();
	}
	
	void print() {
		System.out.format("%d"+")"+
		" [%s] %s  "+"%d¿ø\n",count,code,name,price);
		
	}
}
