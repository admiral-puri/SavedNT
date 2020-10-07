<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.util.Random" %>

<!-- 
if an exception occurs here
then the specific page will be invoked
to output the error status
-->
<%@page errorPage="q.jsp" %>

<%!
//member functions and member variables for the  
//class that will result by compilation of this JSP
    int getNumberBetween1And10()
    {
        Random r = new Random();
        return r.nextInt(11);//0 to 11
    }
    
    String getTitle()
    {
        return "My JSP Study";
    }
%>


<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
<!--
content of titleBar.jsp to be included here at compile time
-->
        <%@include  file="titleBar.jsp" %>
        <h1><%= getTitle()%></h1>
        
        <%
            int q = getNumberBetween1And10();
            if(q == 0)
                throw new Exception("Got a ZERO");
            int i;
            out.println("Multiplication Table of : " + q);
            for(i =1; i < 10; i++)
            {
                out.println("<h2>" + q + " * " + i + " = " + q*i + "</h2>" );
            }
        %>
    </body>
</html>
