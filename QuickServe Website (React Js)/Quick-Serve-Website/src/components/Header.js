import react from "react"

const Header = (props) =>{
    
    return (
        <div>
            <h1 style={{color:"green" ,background:"black"}}>Hello To {props.title}</h1>
        </div>
    )
}
export default Header