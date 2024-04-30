	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	
	typedef struct Vehicle {
	    char id[20];
	    char route[20];
	    int speed;
	    struct Vehicle* next;
	} Vehicle;
	
	
	Vehicle* createVehicle(char id[], char route[], int speed) {
	    Vehicle* newVehicle = (Vehicle*)malloc(sizeof(Vehicle));
	    if (newVehicle == NULL) {
	        printf("Memory allocation failed.\n");
	        exit(1);
	    }
	    strcpy(newVehicle->id, id);
	    strcpy(newVehicle->route, route);
	    newVehicle->speed = speed;
	    newVehicle->next = NULL;
	    return newVehicle;
	}
	
	void addVehicle(Vehicle** head, char id[], char route[], int speed) {
	    Vehicle* newVehicle = createVehicle(id, route, speed);
	    if (*head == NULL) {
	        *head = newVehicle;
	    } 
		
		else {
	        Vehicle* current = *head;
	        while (current->next != NULL) {
	            current = current->next;
	        }
	        current->next = newVehicle;
	    }
	}
	
	void displayVehicles(Vehicle* head) {
	    if(head==NULL){
	        printf("No vehicles\n");
	        return;
	    }
	    Vehicle* current = head;
	    while (current != NULL) {
	        printf("Vehicle %s added to Route %s with a speed of %d mph.\n", current->id, current->route, current->speed);
	        current = current->next;
	    }
	}
	
	const char* traffic_density(int x){
	    if(x<3){
	        return "Light Traffic";
	    }
	    
	    else if(x>=3 && x<=5){
	        return "Moderate Traffic";
	        
	    }
	    
	    else if(x>5){
	        return "Heavy Traffic";
	    }
	}
	
	
	
	int main() {
	    Vehicle* head = NULL;
	    char id[20];
	    char route[20];
	    int speed;
	    int choice;
	    int total_A = 0, total_B = 0, total_C = 0, total_D = 0, c_A=0, c_B=0, c_C=0, c_D=0, avg_A = 1, avg_B = 1, avg_C = 1, avg_D = 1;
	
	    while(1){
	        printf("1. Click 1: to add data of the vehicle\n2. Click 2: to add an intersection for traffic\n3. Display the vehicle additions\n4. Click 4: Traffic Condition \n5. Click 5: To Quit");	
	        scanf("%d", &choice);
	        if(choice==1){
	            printf("Enter Vehicle ID: ");
	            scanf("%s", id);
	            printf("Enter Route: ");
	            scanf("%s", route);
	            printf("Enter Speed (mph): ");
	            scanf("%d", &speed);
	            
	            if(strcmp(route, "A") == 0){
	                total_A += speed; 
	                c_A++;
	            }
	            else if(strcmp(route, "B") == 0){
	                total_B += speed; 
	                c_B++;
	            }
	            else if(strcmp(route, "C") == 0){
	                total_C += speed; 
	                c_C++;
	            }
	            else if(strcmp(route, "D") == 0){
	                total_D += speed; 
	                c_D++;
	            }
	
	            
	            addVehicle(&head, id, route, speed);
	        }
	        
	        else if(choice==2){
	        	printf("Optimize Traffic Signals ar Intersection: \n");
	        	char intersection_point;
	        	scanf("%s", &intersection_point);
	        	printf("Traffic signals optimized at %c\n", intersection_point);
	        }
	        
	        else if(choice==3){
	            displayVehicles(head);
	        }
	        
	        else if(choice==4){
	            avg_A = total_A / c_A;
	            avg_B = total_B / c_B;
	            avg_C = total_C / c_C;
	            avg_D = total_D / c_D;
	            
	            const char *d_A = traffic_density(c_A);
	            const char *d_B = traffic_density(c_B);
	            const char *d_C = traffic_density(c_C);
	            const char *d_D = traffic_density(c_D);
	            
	            printf("Route A: %s, Avergae Speed: %d mph\n", d_A, avg_A);
	            printf("Route B: %s, Avergae Speed: %d mph\n", d_B, avg_B);
	            printf("Route C: %s, Avergae Speed: %d mph\n", d_C, avg_C);
	            printf("Route D: %s, Avergae Speed: %d mph\n", d_D, avg_D);
	        }
	        
	        else if(choice==5){
	            break;
	        }
	    }
	}
