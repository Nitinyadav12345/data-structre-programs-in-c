package com.example.tictactoe20;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {
    boolean gameactive = true;
    int activeplayer = 0;
    // 1->0 0->x 2->null
    int[] gamestate = {2,2,2,2,2,2,2,2,2};
    int[][] winpositions = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,8},{2,5,8},{0,4,8},{2,4,6}};

    public void playerTap(View view){
        boolean x=false;
        ImageView img = (ImageView)view;
        int taped_img = Integer.parseInt(img.getTag().toString());
        for(int i=0; i<gamestate.length; i++){
            if(gamestate[i] == 2)
                x=true;
        }
        if(!gameactive || !x ){
            gamereset(view);
        }
        if(gamestate[taped_img] == 2){
            gamestate[taped_img] = activeplayer;
            img.setTranslationY(-1000f);
            if(activeplayer == 0){
              img.setImageResource(R.drawable.x);
              activeplayer = 1;
              TextView status = findViewById(R.id.textView4);
              status.setText("IT'S YOUR TURN");
              TextView status1  = findViewById(R.id.textView5);
              status1.setText("");
            }
            else{
                img.setImageResource(R.drawable.o);
                activeplayer = 0;
                TextView status1 = findViewById(R.id.textView5);
                status1.setText("IT'S YOUR TURN");
                TextView status = findViewById(R.id.textView4);
                status.setText("");
            }
            img.animate().translationYBy(1000f).setDuration(300);
        }

        for(int[] winposition:  winpositions){
            if(gamestate[winposition[0]] ==gamestate[winposition[1]] &&
                    gamestate[winposition[1]] ==gamestate[winposition[2]] &&
                    gamestate[winposition[0]] !=gamestate[winposition[2]]
            ){
                String winstr;
                gameactive = false;
                if(gamestate[winposition[0]] == 0){
                    winstr = "PLAYER 1 has won";
                    TextView status = findViewById(R.id.textView4);
                    status.setText(winstr);
                }
                else {
                    winstr = "PLAYER 2 has won";

                    TextView status1 = findViewById(R.id.textView5);
                    status1.setText(winstr);
                }
            }
        }

    }
    public void gamereset(View view) {
        gameactive = true;
        activeplayer = 0;
        for(int i=0; i<gamestate.length; i++){
            gamestate[i] = 2;
        }
        ((ImageView)findViewById(R.id.imageView0)).setImageResource(0);
        ((ImageView)findViewById(R.id.imageView1)).setImageResource(0);
        ((ImageView)findViewById(R.id.imageView2)).setImageResource(0);
        ((ImageView)findViewById(R.id.imageView3)).setImageResource(0);
        ((ImageView)findViewById(R.id.imageView4)).setImageResource(0);
        ((ImageView)findViewById(R.id.imageView5)).setImageResource(0);
        ((ImageView)findViewById(R.id.imageView6)).setImageResource(0);
        ((ImageView)findViewById(R.id.imageView7)).setImageResource(0);
        ((ImageView)findViewById(R.id.imageView8)).setImageResource(0);

        TextView status = findViewById(R.id.textView4);
        status.setText("IT'S YOUR TURN");

    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);
    }


}
