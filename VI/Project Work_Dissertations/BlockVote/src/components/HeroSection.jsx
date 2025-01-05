import React from "react";
import { NavLink } from "react-router-dom";
import styled from "styled-components";
import { Button } from "../styles/Button";
import { useGlobalContext } from "../context";

const HeroSection = () => {
  const { name, image } = useGlobalContext();

  return (
    <Wrapper>
      <div className="container grid grid-two-column">
        <div className="section-hero-data">

          <h1 className="hero-heading">{name}</h1>
          <h3 className="hero"> I'm {name}. A Complete Solution for Online Voting.</h3>
          <p className="hero-para">
            One People,One Vote,One Value
          </p>
          <Button className="btn getstarted-btn">
            <NavLink to="/contact"> Get Started </NavLink>
          </Button>
        </div>

        {/* for image  */}
        <div className="section-hero-image">
          <picture>
            <img src={image} alt="hero image" className="hero-img " />
          </picture>
        </div>
      </div>
    </Wrapper>
  );
};

const Wrapper = styled.section`
  padding: 9rem 0;

  .section-hero-data {
    display: flex;
    flex-direction: column;
    justify-content: center;
  }

  .btn {
    max-width: 20rem;
  }


  .hero-heading {
    text-transform: uppercase;
    font-size: 6.4rem;
  }
  .hero{
    font-size:2.5rem;
  }

  .hero-para {
    margin-top: 1.5rem;
    margin-bottom: 3.4rem;
    max-width: 60rem;
  }

  .section-hero-image {
    display: flex;
    justify-content: center;
    align-items: center;
  }

  picture {
    text-align: center;
  }

  .hero-img {
    max-width: 80%;
  }

  @media screen and (max-width: 990px) {
    html,body{
        width:100%;
        height:100%;
        margin:0;
        padding:0;
        overflow-x: hidden;
       }
    .gpt3__blog-container {
        flex-direction: column-reverse;
    }


    .gpt3__blog-container_groupA {
        margin: 2rem 0;
    }

    .gpt3__blog-container_groupA .gpt3__blog-container_article  {
       width: 48%;
    }

    .gpt3__blog-container_groupA .gpt3__blog-container_article-image {
        height: 250px;
    }
}

@media screen and (max-width: 700px) {
    html,body{
        width:100%;
        height:100%;
        margin:0;
        padding:0;
        overflow-x: hidden;
       }
    .gpt3__blog-container_groupB {
        grid-template-columns: repeat(1, 1fr);
    }

    .gpt3__blog-container_groupA .gpt3__blog-container_article  {
       width: 100%;
    }

    .gpt3__blog-heading h1 {
        font-size: 46px;
        line-height: 52px;
    }
}

@media screen and (max-width: 550px) {
    html,body{
        width:100%;
        height:100%;
        margin:0;
        padding:0;
        overflow-x: hidden;
       }
    .gpt3__blog-heading h1 {
        font-size: 34px;
        line-height: 42px;
    }

}

  @media (max-width: ${({ theme }) => theme.media.mobile}) {
    .grid {
      gap: 7.2rem;
    }
  }
`;

export default HeroSection;
