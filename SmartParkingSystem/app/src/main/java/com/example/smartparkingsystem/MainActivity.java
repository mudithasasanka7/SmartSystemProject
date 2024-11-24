package com.example.smartparkingsystem;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class MainActivity extends AppCompatActivity {

    private ImageView space1, space2, space3, space4;
    private ImageView car1, car2, car3, car4;

    private DatabaseReference databaseReference;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Initialize views
        space1 = findViewById(R.id.space1);
        space2 = findViewById(R.id.space2);
        space3 = findViewById(R.id.space3);
        space4 = findViewById(R.id.space4);

        car1 = findViewById(R.id.car1);
        car2 = findViewById(R.id.car2);
        car3 = findViewById(R.id.car3);
        car4 = findViewById(R.id.car4);

        // Reference to Firebase Realtime Database
        databaseReference = FirebaseDatabase.getInstance()
                .getReference(); // Root reference

        // Add a listener to retrieve data from Firebase
        databaseReference.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(@NonNull DataSnapshot snapshot) {
                // Read and update the UI for each parking space
                Boolean space1Status = snapshot.child("space1").child("status").getValue(Boolean.class);
                Boolean space2Status = snapshot.child("space2").child("status").getValue(Boolean.class);
                Boolean space3Status = snapshot.child("space3").child("status").getValue(Boolean.class);
                Boolean space4Status = snapshot.child("space4").child("status").getValue(Boolean.class);

                updateParkingSpace(space1Status, space1, car1);
                updateParkingSpace(space2Status, space2, car2);
                updateParkingSpace(space3Status, space3, car3);
                updateParkingSpace(space4Status, space4, car4);
            }

            @Override
            public void onCancelled(@NonNull DatabaseError error) {
                Log.e("Firebase", "Error reading database", error.toException());
            }
        });
    }

    // Helper method to update UI based on parking space availability
    private void updateParkingSpace(Boolean isAvailable, ImageView space, ImageView car) {
        if (isAvailable != null && isAvailable) {
            // If space is available
            space.setBackgroundColor(Color.GREEN);
            car.setVisibility(View.GONE); // Hide car
        } else {
            // If space is occupied
            space.setBackgroundColor(Color.RED);
            car.setVisibility(View.VISIBLE); // Show car
        }
    }
}
