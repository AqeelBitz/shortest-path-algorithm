#include <iostream>
#include <vector>
#include <queue>
#include <time.h>
#include <ctime>
#include <set>
#include <windows.h>
#include "Login.h"
#define MAX 10000000
using namespace std;


//////////////  BELLMAN FORD ////////////
vector < vector < pair <int , int > > > FormAdjacencyList(){
	
	vector < vector <pair <int , int > > > AdjacencyList ;
	
	int no_of_vertices = 7 ;
	
	for(int i = 0 ; i < no_of_vertices ; i++ )
	{
		vector< pair <int , int > > Row ;
		AdjacencyList.push_back(Row) ;
	} 
	int i = 0 ;
	AdjacencyList[i].push_back(make_pair ( 1 , 2 ) ) ;
	AdjacencyList[i].push_back(make_pair ( 2 , 3 ) ) ;
	i++;
	AdjacencyList[i].push_back(make_pair ( 0 , 2 ) ) ;
	AdjacencyList[i].push_back(make_pair ( 5 , 1 ) ) ;
	i++;
	AdjacencyList[i].push_back(make_pair ( 0 , 3 ) ) ;
	AdjacencyList[i].push_back(make_pair ( 5 , 2 ) ) ;
	AdjacencyList[i].push_back(make_pair ( 3 , 6 ) ) ;
	i++;
	AdjacencyList[i].push_back(make_pair ( 4 , -7 ) ) ;
	AdjacencyList[i].push_back(make_pair ( 2 , 6 ) ) ;
    AdjacencyList[i].push_back(make_pair ( 1 , 4 ) ) ;
    i++;
    AdjacencyList[i].push_back(make_pair ( -2 , 6 ) ) ;
    AdjacencyList[i].push_back(make_pair ( 7 , 5 ) ) ;
    AdjacencyList[i].push_back(make_pair ( 4 , 3 ) ) ;
    i++; 
    AdjacencyList[i].push_back(make_pair ( 6 , 8 ) ) ;
    AdjacencyList[i].push_back(make_pair ( -2 , -2 ) ) ;
    AdjacencyList[i].push_back(make_pair ( 7 , 7 ) ) ;
    AdjacencyList[i].push_back(make_pair ( 5 , 4 ) ) ;  
    i++;
    AdjacencyList[i].push_back(make_pair ( 4 , -8 ) ) ;
    AdjacencyList[i].push_back(make_pair ( 7 , 2 ) ) ;
    AdjacencyList[i].push_back(make_pair ( 1 , 3 ) ) ;

    return AdjacencyList ;
}


vector <int > BellmanFordsAlgo( vector < vector < pair <int , int > > > &AdjacencyList , int &S1)
{
	cout<<"\t\t\t\tGetting the shortest path from "<<S1 <<" to all other node."<<endl<<endl<<endl; 
	vector <int > Distance ;
	
	int SIZE = AdjacencyList.size() ;
	for (int i = 0 ; i < SIZE ; i++ ){
		Distance.push_back(MAX) ;
	}
	Distance[S1] = 0 ;
	
	for(int i = 0 ; i < SIZE-1 ; i++ ){
		for(int j = 0 ; j < SIZE ; j++ ){
			for(int k = 0 ; k < AdjacencyList[j].size() ; k++ ) 		
			{
				int vertex = AdjacencyList[j][k].first ;
				int weight = AdjacencyList[j][k].second ; 
				
				if(Distance[vertex] > Distance[j] + weight ){
					Distance[vertex] = Distance[j] + weight ;
				}
			}
		}
	}
	return Distance ;
}


void Print_shortest_distance ( vector <int> Distance , int src ){

	cout<<"\t\t\t\tPrinting the shortest paths for node "<< src <<" :"<<endl<<endl;
	
	for(int i = 0 ; i < Distance.size() ; i++)
		cout<<"\t\t\t\tThe distance from node  "<<src<<" to node  "<<i<<" is:"<<Distance[i]<<endl<<endl;
	
		cout<<"\t\tThe shortest distance from 0 to all other nodes is given below( in a single line)."<<endl;
	cout<<"\t\t";
	for(int i = 0 ; i < Distance.size() ; i++)
		cout<<"\t"<<i;
		
		cout<<"\n\n" ;
	cout<<"\t\t";

	for(int i = 0 ; i < Distance.size() ; i++)
		cout<<"\t"<<Distance[i];
			
	cout<<endl<<endl<<endl;
}



////////// JOHNSONS ////////////

vector< vector<pair<int, int> > > form_adj_list()
{
    vector< vector<pair<int, int> > > adj_list;
    
    int num_of_vertices = 7;
    
    for(int i = 0; i < num_of_vertices; i++)
    {
        vector<pair<int, int> > row;
        adj_list.push_back(row);
    }
    
    adj_list[0].push_back(make_pair(1, 2) ) ;
    adj_list[0].push_back(make_pair(2, 3) ) ;
    
    adj_list[1].push_back(make_pair(0, 2) ) ;
    adj_list[1].push_back(make_pair(5, 1) ) ;
    
    adj_list[2].push_back(make_pair(0, 3) ) ;
    adj_list[2].push_back(make_pair(5, 2) ) ;
    
    adj_list[3].push_back(make_pair(1, 4) ) ;
    adj_list[3].push_back(make_pair(4, 1) ) ;
    adj_list[3].push_back(make_pair(6, 2) ) ;
    
    adj_list[4].push_back(make_pair(3, 1) ) ;
    adj_list[4].push_back(make_pair(5, 2) ) ;
    adj_list[4].push_back(make_pair(6, 1) ) ;
    
    adj_list[5].push_back(make_pair(1, 1) ) ;
    adj_list[5].push_back(make_pair(2, 2) ) ;
    adj_list[5].push_back(make_pair(4, 2) ) ;
    adj_list[5].push_back(make_pair(6, 2) ) ;
    
    adj_list[6].push_back(make_pair(3, 2) ) ;
    adj_list[6].push_back(make_pair(4, 1) ) ;
    adj_list[6].push_back(make_pair(5, 2) ) ;
    
    return adj_list;
}

vector <vector <pair <int , int > > > BellmanFord(vector< vector<pair<int, int> > > &adj_list, int &start)
{
    cout << "\nGetting the shortest path from " << start << " to all other nodes.\n";
    vector<int> distance;
    vector < vector < pair < int , int > > > new_distance;
    
    int num_of_vertices = adj_list.size();
    for (int i = 0; i < num_of_vertices; i++) 
	{
        new_distance.push_back(vector<pair<int, int> >());
        for (int j = 0; j < (adj_list[i].size()); j++) 
		{
            new_distance[i].push_back(pair<int, int>(0, 0));
        }
    }

    for(int i = 0; i < num_of_vertices; i++)
    {
        distance.push_back(MAX); 
    }
        
    distance[start] = 0;    
    
    for(int i = 0; i < num_of_vertices-1; i++)
    {
        for(int u = 0; u < num_of_vertices; u++)
        {
            for(int j = 0; j < adj_list[u].size(); j++)
            {
                int vertex = adj_list[u][j].first;
                int weight = adj_list[u][j].second;
                new_distance[u][j].first =  adj_list[u][j].first ;
                
                if(distance[vertex] > distance[u] + weight)
                {
                    distance[vertex] = distance[u] + weight;
                    new_distance[u][j].second =  distance[vertex] ;
                }
                else
				{
                    new_distance[u][j].second =  adj_list[u][j].second ;
				}
            }
        }
    }            
    return new_distance;
}

vector <int>  Dijkstra(vector< vector<pair<int, int> > > &adj_list, int &start)
{
    vector <int> distance;
    
    int num_of_vertices = adj_list.size();
    for(int i = 0; i < num_of_vertices; i++)
    {
        distance.push_back(MAX); 
    }
        
    priority_queue<pair<int, int>, vector< pair<int, int> >, greater<pair<int, int> > > pqueue;
    
    pqueue.push(make_pair(start, 0));
    distance[start] = 0;
    
    while(pqueue.empty() == false)
    {
        int u = pqueue.top().first;
        pqueue.pop();
        
        for(int i = 0; i < adj_list[u].size(); i++)
        {
            int vertex = adj_list[u][i].first;
            int weight = adj_list[u][i].second;
            
            if(distance[vertex] > distance[u] + weight)
            {
                distance[vertex] = distance[u] + weight;
                pqueue.push(make_pair(vertex, distance[vertex]));
            }
        }
    }
    return distance;
}
void print_shortest_path(vector<int> &distance, int &start)
{
    cout << "\n\t\tPrinting the shortest paths for node " << start << ".\n\n";
    for(int i = 0; i < distance.size(); i++)
    {
        cout << "\t\tThe distance from node " << start << " to node " << i << " is: " << distance[i] << endl;
    }
}
 
void johnson()
{
    vector< vector<pair<int, int> > > adj_list = form_adj_list();

    vector < vector < pair <int , int > > >  distance;
    vector<int> dist1;
            
    for(int i = 0; i < adj_list.size(); i++) 
	{
        distance = BellmanFord(adj_list, i);
        dist1 = Dijkstra(distance, i);
        print_shortest_path(dist1, i);
        for (int i = 0; i < distance.size(); i++) 
		{
            distance[i].clear();
        }

        distance.clear();
        dist1.clear();
    }
}



////////// FLOYD WARSHALL ////////////



vector<vector<int> > form_adjMatrix()
{
    vector< vector<int> > adj_matrix;

    const int num_of_vertices = 4;

    for(int i = 0; i < num_of_vertices; i++)
    {
        vector<int> row;
        adj_matrix.push_back(row);
        
        for(int j = 0; j < num_of_vertices; j++)
        {
            int inf = MAX; 
            if(i == j) 
            { 
			    inf = 0; 
			}
		    adj_matrix[i].push_back(inf);
        }
    }
    
    adj_matrix[0][1] = 9;
    adj_matrix[1][0] = 6;
    
    adj_matrix[0][2] = -4;
    adj_matrix[2][1] = 5;
    
    adj_matrix[1][3] = 4;
    adj_matrix[3][2] = 8;
	
////  for num_of_vertices = 7 ////

//    adj_matrix[1][5] = 2;
//    adj_matrix[5][1] = 2;
//    
//    adj_matrix[2][5] = 4;
//    adj_matrix[5][2] = 3;
//    
//    adj_matrix[3][4] = -1;
//    adj_matrix[4][3] = 5;
//    
//    adj_matrix[3][6] = 6;
//    adj_matrix[6][3] = 4;
//    
//    adj_matrix[4][5] = 1;
//    adj_matrix[5][4] = 7;
//    
//    adj_matrix[4][6] = 4;
//    adj_matrix[6][4] = 5;
//    
//    adj_matrix[5][6] = 3;
//    adj_matrix[6][5] = 1; 
	   
    return adj_matrix;
}
    
vector< vector<int> > FloydWarshallAlgo(vector< vector<int> > &adj_matrix)
{
    vector< vector<int> > distance;
    
    int num_of_vertices = adj_matrix.size();
    for(int i = 0; i < num_of_vertices; i++)
    {
        vector<int> row;
        distance.push_back(row);
        for(int j = 0; j < num_of_vertices; j++)
        {
            distance[i].push_back(adj_matrix[i][j]);
        }
    }
    
    for(int k = 0; k < num_of_vertices; k++)
    {
        for(int i = 0; i < num_of_vertices; i++)
        {
            for(int j = 0; j < num_of_vertices; j++)
            {
                if(distance[i][k] + distance[k][j] < distance[i][j])
                {
                    distance[i][j] = distance[i][k] + distance[k][j];
                }
            }
        }
    }
    return distance;
}

static int count = 0, cnt = 0;    
void Display_shortest_path(vector< vector<int> > &distance)
{
    cout << "\nDisplaying the shortest paths for all nodes.\n";
    for(int i = 0; i < distance.size(); i++)
    {
        for(int j = 0; j < distance.size(); j++)
        {
            cout << "\t\t\tThe shortest distance from node " << i << " to node " << j << " is: " << distance[i][j] << endl;
        }
        cout << endl;
    }
    cout << "\t\t\t" << "Distance in matrix form: " << endl << endl;
    cout << "\t";
	
	for(const vector<int> &d : distance)
    {
        cout << "\t        " << cnt++;
	}
	cout << endl;
	cout << "\t\t\t-------------------------------------------------" << endl;
	
	for(const vector<int> &d : distance )
    {
    	cout << "\t\t " << count++ << "|";
        for( int x : d ) 
		{
			cout << "\t" << x << "\t";
		}
        cout << endl;
    }
    cout << endl;
}

void MainMenu()
{
	int choice;
	system("cls");
	TitleScreen();
		cout << "\n\t\t\t\t\t 1) BELLMAN-FORD ALGORITHM" << endl
        << "\t\t\t\t\t 2) JOHNSONS ALGORITHM" << endl
		<< "\t\t\t\t\t 3) FLOYD-WARSHALL ALGORITHM" << endl
		<< "\t\t\t\t\t 4) Exit" << endl;
		cout << "\n\t\t\t\tChoose from 1 to 4 to proceed...";	
		cin >> choice;
		switch(choice)
		{
		    case 1:
	        {
				system("cls");
				cout << "Program started.\n";
				vector < vector < pair <int , int > > > AdjacencyList = FormAdjacencyList() ;
	
	            int src = 0 ;

        		vector <int > distance = BellmanFordsAlgo(AdjacencyList , src) ;
	
	            Print_shortest_distance(distance , src ) ;
	            cout << "Program ended." << endl;
                cout << "Press any key to return to mainmenu..." << endl;
		        getch();
	            MainMenu();
			}
			break;
			case 2:
			{
				system("cls");
				cout << endl << "Program started.\n" << endl;
				
				johnson();
                
				cout << endl << "Program ended." << endl;
                cout << endl << "Press any key to return to mainmenu..." << endl;
		        getch();
	            MainMenu();
			}
			break;
			case 3:
			{
				system("cls");
				cout << "Program started.\n";
                vector< vector<int> > adj_matrix = form_adjMatrix();
    
                vector< vector<int> > distance = FloydWarshallAlgo(adj_matrix);
    
                Display_shortest_path(distance);
                cout << "Program ended." << endl;
                cout << "Press any key to return to mainmenu..." << endl;
		        getch();
	            MainMenu();
            }
            break;
			case 4:	
    		{
                Exit();
			}			
		    break;
			default:
				cout << "Invalid Choice!";
				delay(500);
				MainMenu();
		}
		system("cls");
}
    
int main() 
{
	loading();
    TitleScreen();
    WelcomeScreen();
    
    MainMenu();
    return 0;
}
