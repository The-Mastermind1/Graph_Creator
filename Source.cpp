#include "Header.h"
#include<httplib.h>
#include<string_view>
//void* operator new(size_t size) {
//    printf("%zu\n", size);
//    return malloc(size);
//}


int main() {
    httplib::Server svr;
    
    svr.set_mount_point("/static", "./static");
    // Serve the HTML page
    svr.Get("/", [](const httplib::Request& req, httplib::Response& res) {
       const char* html_content = R"(
          <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Graph Simulator</title>
    <!-- Προσθήκη Google Fonts -->
    <link href="https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;600&display=swap" rel="stylesheet">
    <style>
        /* Γενικό στυλ για τη σελίδα */
        body {
            font-family: 'Poppins', sans-serif;
            background-color: #f5f7fa;
            margin: 0;
            padding: 0;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
            flex-direction: column;
            color: #333;
        }

        h1 {
            color: #2c3e50;
            font-size: 2.5em;
            margin-bottom: 20px;
            text-align: center;
            font-weight: 600;
        }

        /* Κουτί Οδηγιών (cloud) */
        .cloud {
            background-color: #ffffff;
            padding: 25px;
            border-radius: 12px;
            border: 1px solid #ddd;
            box-shadow: 0 4px 15px rgba(0, 0, 0, 0.1);
            width: 80%;
            max-width: 420px;
            margin-bottom: 25px;
            transition: all 0.3s ease;
        }

        .cloud:hover {
            box-shadow: 0 6px 20px rgba(0, 0, 0, 0.15);
        }

        .cloud p {
            font-size: 1.1em;
            color: #7f8c8d;
        }

        .cloud ol {
            padding-left: 20px;
            font-size: 1em;
            color: #95a5a6;
        }

        /* Στυλ για την φόρμα */
        .exisosi {
            display: flex;
            justify-content: center;
            align-items: center;
            gap: 15px;
            margin-bottom: 20px;
            width: 80%;
            max-width: 400px;
        }

        .arithmoi {
            padding: 12px;
            font-size: 1.2em;
            border-radius: 8px;
            border: 1px solid #ccc;
            outline: none;
            width: 60%;
            background-color: #ecf0f1;
            transition: all 0.3s ease;
        }

        .arithmoi:focus {
            border-color: #3498db;
            box-shadow: 0 0 10px rgba(52, 152, 219, 0.5);
        }

        button {
            padding: 12px 18px;
            background-color: #3498db;
            border: none;
            color: white;
            font-size: 1.2em;
            border-radius: 8px;
            cursor: pointer;
            transition: background-color 0.3s ease, transform 0.2s ease;
        }

        button:hover {
            background-color: #2980b9;
            transform: translateY(-3px);
        }
            #warning {
            color: #cc0000;
            font-weight: bold;
            font-size: 1.1em;
            text-align: center;
            margin-top: 15px;
        }
        /* Responsive design */
        @media (max-width: 600px) {
            .cloud {
                width: 90%;
                padding: 20px;
            }
            

            .arithmoi {
                width: 100%;
            }

            button {
                width: 100%;
                font-size: 1.1em;
            }
        }
    </style>
</head>
<body>

    <h1>Graph Simulator</h1>

    <label for="graph">Enter the function</label>
    <br>

    <form action="/submit" method="post">
       <input type="text" class="arithmoi"  name="function" placeholder="Enter Function">
       <button type="submit">Submit</button>
    </form>
    <br>
    <br>

   <div class="cloud">
        <p>This is what you can use:
            <ol>
                <li>+-ax^n (when the +,-,a is not necessary and a ∈ Z*)</li>
                <li>+-ae^n (when the +,-,a is not necessary n>0 and a ∈ Z*)</li>
                <li>+-alog(n*x) (when the +,-,a is not necessary and a ∈ Z*)</li>
                <li>+-asin(n*x) (when the +,-,a is not necessary and a ∈ Z*)</li>
                <li>+-acos(n*x) (when the +,-,a is not necessary and a ∈ Z*)</li>
                <li>+-a^x (when the +,-,a is not necessary a>0 and a ∈ Z*)</li>
            </ol>
            <p id="warning">!!!Use the + or - a or none of them!!!</p>
        </p>
    </div>

</body>
</html>
        )";
        res.set_content(html_content,std::strlen(html_content), "text/html");
        });

    // Handle form submission
    svr.Post("/submit", [](const httplib::Request& req, httplib::Response& res) {
        const char* kati2 = R"(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Error: No Function Provided</title>
    <style>
        body {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            height: 100vh;
            font-family: Arial, sans-serif;
            background-color: #ffe6e6;
            color: #333;
            text-align: center;
        }

        h1 {
            font-size: 3em;
            color: #cc0000;
            margin-bottom: 20px;
            text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.2);
        }

        a {
            text-decoration: none;
            font-size: 1.5em;
            color: #fff;
            background-color: #cc0000;
            padding: 10px 20px;
            border-radius: 8px;
            box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.2);
            transition: background-color 0.3s ease, transform 0.2s ease;
        }

        a:hover {
            background-color: #990000;
            transform: translateY(-3px);
        }
    </style>
</head>
<body>
    <h1>Error: No function provided</h1>
    <!-- Το κουμπί τώρα οδηγεί στη σελίδα της αρχικής φόρμας -->
    <a href="/">Go Back to Graph Simulator</a>
</body>
</html>)";
        if (req.has_param("function")) {
            using namespace _panagiotis_stelios; 
           
            sf::RenderTexture rendertexture;
            if (!rendertexture.create(800, 600)) {
                throw _FAILED_ACTION{ "Failed to create render texture" };
            }

            sf::Texture texture;
            std::string function_input = req.get_param_value("function");
            try {
                parse_graph(function_input,rendertexture,texture);//use string_view
                const char* kati = R"(<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Function Output</title>
    <style>
        body {
            display: flex;
            flex-direction: column;
            align-items: center;
            justify-content: center;
            height: 100vh;
            font-family: Arial, sans-serif;
            background-color: #f0f8ff;
            color: #333;
            text-align: center;
        }
        h1 {
            font-size: 3em;
            color: #0056b3;
            margin-bottom: 20px;
        }
        img {
            width: 960px;
            height: 540px;
            border: 5px solid #333;
            border-radius: 15px;
            box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.2);
            margin-bottom: 20px;
        }
        a {
            text-decoration: none;
            font-size: 1.5em;
            color: #fff;
            background-color: #0056b3;
            padding: 10px 20px;
            border-radius: 8px;
            box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.2);
        }
        a:hover {
            background-color: #004080;
        }
    </style>
</head>
<body>
    <h1>Received function: <!-- Add dynamic function_input here --></h1>
    <img src="/static/icons/icon.png" alt="icon">
    <br>
    <!-- Εδώ η αλλαγή στο href -->
    <a href="/">Go Back</a> <!-- ΑΛΛΑΓΗ: Το σωστό path -->
</body>
</html>)";
                res.set_content(kati,std::strlen(kati), "text/html");
               /* res.set_content("<h1>Received function: " + function_input + "</h1>"
                    "<img src='/static/icons/icon.png' alt='icon' style='width:1920px;height:1080px;'><br>"
                    "<a href='/'>Go Back</a>", "text/html");*/
            }
            catch (...) {
                
                res.set_content(kati2,std::strlen(kati2), "text/html");
               
            }
           /* res.set_content("<h1>Received function: " + function_input + "</h1>"
                "<img src='/static/icons/icon.png' alt='icon' style='width:1920px;height:1080px;'><br>"
                "<a href='/'>Go Back</a>", "text/html");*/

            

           
        }
        else {
            
            res.set_content(kati2,std::strlen(kati2), "text/html");
        }
        });

    std::cout << "Server started at http://localhost:8080\n";
    svr.listen("0.0.0.0", 8080); // Listen on port 8080

    return 0;
}

