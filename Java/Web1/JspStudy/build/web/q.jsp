<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page isErrorPage="true" %>
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
        
        <h1> Error @ Server </h1>
        <h2> Details : <%= exception.getMessage() %></h2>
        <h2> <a href = "index.jsp"> HOME </a></h2>
        
    </body>
</html>
