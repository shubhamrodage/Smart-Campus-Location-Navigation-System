/* =========================================
   SMART CAMPUS AUTHENTICATION
========================================= */

function checkLogin()
{
    const isLoggedIn =
        localStorage.getItem("isLoggedIn");

    if(isLoggedIn !== "true")
    {
        window.location.replace("login.html");

        return false;
    }

    return true;
}


function logout()
{
    localStorage.removeItem("isLoggedIn");
    localStorage.removeItem("loggedInUserName");

    alert("You have been logged out.");

    window.location.replace("login.html");
}