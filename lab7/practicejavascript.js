

function verifyPassword(){
    var password1 = document.getElementById("password1").value;
    var password2 = document.getElementById("password2").value;

    if (password1.length < 8 || password2.length < 8){
        alert("Passwords must be at least length of 8");
        return;
    }

    if (password1 !== password2){
        alert("Passwords do not match. Please enter the same password twice");
        return;
    }

    alert("Passwords matched! All goodddd")
}