import React, { useEffect, useState } from "react";
import styled from "styled-components";
import { FaArrowUp } from "react-icons/fa";

const GoToTop = () => {
  const [isVisible, setIsVisible] = useState(false);

  const goToBtn = () => {
    window.scrollTo({ top: 0, left: 0, behavior: "smooth" });
  };

  const listenToScroll = () => {
    let heightToHidden = 20;
    const winScroll =
      document.body.scrollTop || document.documentElement.scrollTop;

    if (winScroll > heightToHidden) {
      setIsVisible(true);
    } else {
      setIsVisible(false);
    }
  };

  useEffect(() => {
    window.addEventListener("scroll", listenToScroll);
    return () => window.removeEventListener("scroll", listenToScroll);
  }, []);

  return (
    <Wrapper>
      {isVisible && (
        <div className="top-btn" onClick={goToBtn}>
          <FaArrowUp className="top-btn--icon" />
        </div>
      )}
    </Wrapper>
  );
};

const Wrapper = styled.section`
  display: flex;
  justify-content: center;
  align-items: center;
  position: relative;

  .top-btn {
    font-size: 2.4rem;
    width: 6rem;
    height: 6rem;
    color: #fff;
    background-color: ${({ theme }) => theme.colors.btn};
    box-shadow: ${({ theme }) => theme.colors.shadow};
    border-radius: 50%;
    position: fixed;
    bottom: 5rem;
    right: 5rem;
    z-index: 999;
    display: flex;
    justify-content: center;
    align-items: center;
    cursor: pointer;

    &--icon {
      animation: gototop 1.2s linear infinite alternate-reverse;
    }

    @keyframes gototop {
      0% {
        transform: translateY(-0.5rem);
      }
      100% {
        transform: translateY(1rem);
      }
    }
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
    .top-btn {
      right: 0;
      left: 40%;
    }
  }
`;

export default GoToTop;
