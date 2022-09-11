package day2Project;

import java.util.ArrayList;
import java.util.Scanner;



public class Department {
	Scanner scan=new Scanner(System.in);
	ArrayList<Store> StoreList=new ArrayList<>();
	
	void readAll(){
		Store st=null;
		for(int i=1;i<=33;i++) {
			
			st=new Store();
			st.read(i,scan);
			StoreList.add(st);
		}
	}
	void printAll() {
		for (Store st : StoreList) {
			st.print();
		}
	}
	void run() {
		readAll();
		printAll();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Department m = new Department();
		m.run();

	}

}
