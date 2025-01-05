import React, { useEffect } from "react";
import Extra from "./components/Extra";
import { useGlobalContext } from "./context";

const About = () => {
  const { udpateAboutPage } = useGlobalContext();

  useEffect(() => udpateAboutPage(), []);

  return <Extra />;
  
};

export default About;
