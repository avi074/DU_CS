import React from "react";
import styled from "styled-components";
import team1 from "../assets/img/img_avatar.png";
import { MdOutlineFacebook} from "react-icons/md";
import { FaLinkedin } from "react-icons/fa";
import { FaGithub } from "react-icons/fa";

const Team = () => {
    const Wrapper = styled.section`

.team-section {
  padding: 40px 0;
  text-align: center;
}

.team-container {
  display: flex;
  flex-wrap: wrap;
  justify-content: center;
}

.team-member {
  width: 30%;
  margin: 40px;
  text-align: center;
}

.team-member img {
  width: 100%;
  border-radius: 50%;
}
h1 {

  font-size: 68px;
  text-align: center;
}
h3 {

  font-size: 32px;
  text-align: center;
}
p {

  font-size: 22px;
  line-height: 1.5;
  text-align: justify;
}
.social{
   
  margin: 0 auto;
  text-align: center;
  background-color: #ffffff;
  border: 1px solid #ccc;
}

@media (max-width: 600px) {
  .team-member {
    width: 100%;
  }
}
      `;
    return(
        <Wrapper>
         <section className="team-section">
         <h1>Team</h1>

         <div className="team-container"> 

         <div className="team-member">
          <img src={team1} alt="Team Member 1" />        
          <h3>Ujjawal kumar </h3>
          <p>Hi I am Student of Ramanujan College ,Final Year.I am Intrested in designing and developing.</p>          
          <div className="social">
          <p>Connect to me At: 
           <a href="https://www.linkedin.com/in/ujjawal-kumar-a855541a2/"><FaLinkedin /> </a>
           <a href="https://github.com/Undercoder567"><FaGithub/></a>
           </p>
           </div> 
         </div> 

         <div className="team-member">
          <img src={team1} alt="Team Member 2" />        
          <h3>Avinash Gautam </h3>
          <p>Hi I am product developer and designer.</p>          
          <div className="social">
          <p>Connect to me At: 
           <a href=" https://in.linkedin.com/in/boss-avinashg"><FaLinkedin /> </a>
           <a href="https://github.com/Avinash-msc"><FaGithub/></a>
           </p>
           </div> 
         </div> 

         <div className="team-member">
          <img src={team1} alt="Team Member 3" />        
          <h3>Hitesh Harsh</h3>
          <p>Hi I am product developer and designer.</p>          
          <div className="social">
          <p>Connect to me At: 
           <a href="https://www.linkedin.com/in/hitesh-harsh/"><FaLinkedin /> </a>
           <a href="https://github.com/Hitesh-Harsh"><FaGithub/></a>
           </p>
           </div> 
         </div> 

         <div className="team-member">
          <img src={team1} alt="Team Member 4" />        
          <h3>Adarsh</h3>
          <p>Hi I am product developer and designer.</p>          
          <div className="social">
          <p>Connect to me At: 
           <a href=""><FaLinkedin /> </a>
           <a href="https://github.com/adarshjudoka212"><FaGithub/></a>
           </p>
           </div> 
         </div> 

         </div>
         </section>
        </Wrapper>
    );
};

export default Team;