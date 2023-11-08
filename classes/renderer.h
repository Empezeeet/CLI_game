//
// Created by Empezeeet on 03/11/2023.
// Uses CLYDE CLI Graphic Engine

#ifndef CLI_GAME_RENDERER_H
#define CLI_GAME_RENDERER_H

#include <vector>
#include <iostream>
#include <thread>
// clear command. thanks windows.
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define CLEAR "cls"
   #define OS "WIN"
#elif __APPLE__
#define CLEAR "clear"
#define OS "MAC"
#else
#define CLEAR "clear"
    #define OS "LINUX"
#endif

#define HIDE_CURSOR "\e[?25l"
#define SHOW_CURSOR "\e[?25h"




namespace clyde {


    enum FPS {
        FPS_60 = 16,
        FPS_30 = 33,
        FPS_15 = 66,
        FPS_10 = 100,
        FPS_5 = 200,
        FPS_2 = 500,
        FPS_1 = 1000
    };

    struct Object {
        int x;
        int y;
        char letter;
        Object(int x, int y, char letter) : x(x), y(y), letter(letter) {}
    };

    typedef std::vector<Object> object_list;
    typedef std::vector< std::vector<char> > Frame;
    
    class Renderer {
    private:
        object_list _objects;
       

    public:
        Frame frame;
        int width;
        
        int height;
        int fps;
        bool running=false;
        // pointer to frame variable
        Frame *frame_ptr = &frame;


        /**
         * @brief Construct a new Renderer object
         * 
         * @param w max width of frame
         * @param h max height of frame
         * @param f FPS count.
         */
        Renderer(int w, int h, FPS f) {
           
            width = w;
            height = h;
            fps = f;

            // hide cursor
            std::cout << HIDE_CURSOR;




            // Initialize frame and clear frame
            this->frame = std::vector< std::vector<char> >(h, std::vector<char>(w));

            this->clear_frame();

        }
        /**
         * @brief Get the max width of renderer object
         * 
         * @return int 
         */
        int get_width() { return this->width; }

        /**
         * @brief Get the max height of renderer object
         * 
         * @return int 
         */
        int get_height() { return this->height; }

        /**
         * @brief Renders frame 
         * 
         * @param objs object_list
         */
        void render(object_list objs) {
            this->prepare_objects(objs);
            this->prepare_frame(this->_objects);
            this->render_frame();
        }
		/**
		 * Generates text
		 * @param x start point x
		 * @param y start point y
		 * @param text text
		 * @return object_list type
		 */
	    object_list generate_text(int x, int y, std::string text) {
		    object_list out_text = {};
		    for (char c : text) {
			    out_text.push_back({x,y,c});
				x++;
		    }
			return out_text;
	    }
        /**
         * Generates shape.
         * @param x horizontal start point
         * @param y vertical start point
         * @param w width of shape
         * @param h height of shape
         * @param c type of shape (only 'r' - rectangle works)
         * @param letter ASCII symbol (brick of object)
         * @return object_list type. {{ { 0, 0, 'n' } }} if something went wrong.
         */

        object_list generate_shape(int x, int y, int w, int h, char c, char letter) {
            // TODO: should check is in bounds of renderer
            object_list shape;
            switch (c) {
                case 'r':
                    return this->generate_rectangle(x, y, w, h, letter);
                default:
                    return { {{0, 0, 'n'}} };
            }
        }
        /**
         * @brief Clears frame
         * 
         */
        void clear_frame() {
            if (this->frame.empty()) return; // frame is empty.
            /// verify this but should be faster:
            // myVector.assign(myVector.size(), ' ');
            for (int y=0; y<=get_height()-1; y++) {
                for (int x=0; x<=get_width()-1; x++) {
                    this->frame[y][x] = ' ';
                }
            }
        

        }
        std::vector< std::vector<char> > prepare_frame(object_list objects) {
            // Prepare frame
            // Returns frame
            // You can use this function to prepare a frame but not show in CLI.

            // Clear frame
            this->clear_frame();
            if (objects.empty()) return; // objects are empty so nothing to render.

            for (int i=0; i<=objects.size(); i++) {

                // use frame_ptr to set object at its position in frame variable
                if (objects[i].x > this->get_width()-1) continue;
                if (objects[i].y > this->get_height()-1) continue;

                //frame[objects[i].x][objects[i].y] = objects[i].letter;
                // do the same like above but using frame pointer
                this->frame_ptr->at(objects[i].y).at(objects[i].x) = objects[i].letter;

            }
            

            return this->frame;
        }

        void prepare_objects(object_list objects) {
            this->_objects = objects;
        }

        void render_frame() {
            system(CLEAR);
            for (int y=0; y<this->get_height()-1; y++) {
                for (int x=0; x<this->get_width()-1; x++) {
                    std::cout << this->frame[y][x];
                }
                std::cout << std::endl;
            }
        }

    private:
        object_list generate_rectangle(int x, int y, int w, int h, char letter) {
            // TODO: should check is in bounds of renderer
            // x: x of top left corner
            // y: y of top left corner
            // w: width
            // h: height

            object_list rectangle;
            for (int i=0; i<h; i++) {
                for (int j=0; j<w; j++) {
                    if (x+j > width-1) continue;
                    if (y+i > height-1) continue;
                    rectangle.push_back({Object(x+j, y+i, letter)});
                }
            }

            return rectangle;
        }



    };
}



#endif //CLI_GAME_RENDERER_H