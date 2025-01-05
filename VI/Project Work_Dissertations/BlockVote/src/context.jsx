import React, { useContext, useReducer, useEffect } from "react";
import reducer from "./reducer";

const AppContext = React.createContext();

const API = "#";

const intialState = {
  name: "",
  image: "",
  services: [
    {
      "id": 1,
      "name": "E-Voting",
      "image": "../assets/voting.gif",
      "description": "E-voting using blockchain is a secure and transparent way of conducting elections through a decentralized and distributed ledger. The blockchain technology enables the creation of a tamper-proof and auditable record of every vote cast, which helps to eliminate fraud and manipulation."
    },

    {
     "id": 2,
    "name": "Security",
    "image": "../assets/security.webp",
    "description": "When a transaction is made on a blockchain, it is verified and recorded by multiple nodes in the network. Each node stores a copy of the entire blockchain, and any attempt to alter a previous transaction would require a consensus among the majority of the nodes in the network. This makes it nearly impossible to alter or corrupt the data on the blockchain without being detected."
 },

 {
  "id": 3,
  "name": "Privacy",
  "image": "../assets/privacy.webp",
  "description": " blockchain can be used to enhance privacy: Blockchain allows users to conduct transactions using pseudonyms instead of their real identities, which can help to protect their privacy."
},

{
  "id": 4,
  "name": "Crypto",
  "image": "../assets/crpto.jpg",
  "description": " Cryptocurrencies are based on blockchain technology, which provides a decentralized and transparent ledger to track and verify transactions. In a blockchain network, cryptocurrency is used as a means of exchange for goods and services. Cryptocurrencies are typically decentralized and not controlled by any government or financial institution, which means they are not subject to the same regulations and restrictions as traditional currencies."
},

{
  "id": 5,
  "name": "Smart Contract",
  "image": "../assets/What_Are_Smart-Contract.jpg",
  "description": "A smart contract is a self-executing computer program that is stored on a blockchain and automatically enforces the rules and regulations of a contract. Smart contracts are a key feature of blockchain technology, enabling secure and transparent transactions without the need for intermediaries."
},

{
  "id": 6,
  "name": "Transparency",
  "image": "../assets/transparency.webp",
  "description": "Transparency is one of the core features of blockchain technology. In a blockchain network, all transactions are recorded and verified by a decentralized network of nodes, and the data is stored on a distributed ledger that is transparent and accessible to anyone with access to the network."
},

],
};

const AppProvider = ({ children }) => {
  const [state, dispatch] = useReducer(reducer, intialState);

  const updateHomePage = () => {
    return dispatch({
      type: "HOME_UPDATE",
      payload: {
        name: "BlockVote",
        image: "./images/ai.png",
      },
    });
  };

  const udpateAboutPage = () => {
    return dispatch({
      type: "ABOUT_UPDATE",
      payload: {
        name: "BlockVote",
        image: "./images/about1.svg",
      },
    });
  };

  //  to get the api data
  const getServices = async (url) => {
    try {
      const res = await fetch(url);
      const data = await res.json();
      dispatch({ type: "GET_SERVICES", payload: data });
    } catch (error) {
      console.log(error);
    }
  };

  // to call the api
  useEffect(() => {
    getServices(API);
  }, []);

  return (
    <AppContext.Provider value={{ ...state, updateHomePage, udpateAboutPage }}>
      {children}
    </AppContext.Provider>
  );
};

// gloabal custom hook
const useGlobalContext = () => {
  return useContext(AppContext);
};

export { AppProvider, useGlobalContext };
